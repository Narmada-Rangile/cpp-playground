import re
import math
import io
from xml.etree import ElementTree as ET
from PIL import Image, ImageDraw, ImageFont
import cairosvg

# --- CONFIGURATION (Simulating game_config.json) ---
HUNTER_NAME = "DILICALFLAME"
PROJECT_NAME = "C++ PLAYGROUND"
ROADMAP_PATH = "roadmap.md"

# Asset paths
ASSET_DIR = "Resources/assets/"
FONT_DIR = "Resources/fonts/"
LAPTOP_SVG_PATH = f"{ASSET_DIR}laptop.svg"
FOLDER_SVG_PATH = f"{ASSET_DIR}folder.svg"
SWORD_SVG_PATH = f"{ASSET_DIR}sword.svg"
FLAG_SVG_PATH = f"{ASSET_DIR}flag.svg"
FONT_PATH = f"{FONT_DIR}VT323-Regular.ttf"

# GIF settings
WIDTH, HEIGHT = 800, 350
NUM_FRAMES = 24
DURATION = 120

# Colors
COLOR_BG = "#000000"  # Black background
COLOR_GRID = "#420000"  # Deeper red grid for better visibility
COLOR_TEXT = "#ffffff"  # Pure white for text for better readability
COLOR_BAR_BG = "#3a3a3a"  # Darker background for progress bar
COLOR_BAR_FILL = "#ff0000"  # Brighter red for progress bar fill
COLOR_SPARKLE = "#ffff00"  # Yellow sparkles
FOLDER_COLOR_INACTIVE = "#cc0000"  # Red for inactive folders
FOLDER_COLOR_ACTIVE = "#ffffff"  # White for active folders

# Leveling system
LEVEL_THRESHOLDS = {
    "F": 0, "E": 25, "D": 75, "C": 150, "B": 250, "A": 375, "S": 450
}

# --- HELPER FUNCTIONS ---

def parse_roadmap(filepath):
    """Parses a markdown file to count total and completed tasks."""
    try:
        with open(filepath, 'r', encoding='utf-8') as f:
            content = f.read()
        tasks = re.findall(r"- \[[x ]\]", content)
        completed = content.count("- [x]")
        return completed, len(tasks)
    except FileNotFoundError:
        print(f"Warning: Roadmap file not found at '{filepath}'. Using default values.")
        return 35, 500

def calculate_stats(completed, total, thresholds):
    """Calculates player rank, level, and progress."""
    rank = "F"
    for r, threshold in thresholds.items():
        if completed >= threshold:
            rank = r
    level = 1 + (completed // 10)
    tasks_into_level = completed % 10
    progress_percent = (tasks_into_level / 10) * 100
    return {
        "rank": rank, "xp": completed, "level": level,
        "next_level": level + 1, "level_progress_percent": progress_percent
    }

def colorize_svg(svg_path, new_color):
    """Reads an SVG, changes its fill color, and returns the SVG data as a string."""
    try:
        ET.register_namespace("", "http://www.w3.org/2000/svg")
        tree = ET.parse(svg_path)
        root = tree.getroot()
        for path in root.findall('.//{http://www.w3.org/2000/svg}path'):
            path.set('fill', new_color)
        return ET.tostring(root, encoding='unicode')
    except (FileNotFoundError, ET.ParseError) as e:
        print(f"Error processing SVG {svg_path}: {e}")
        return None

def svg_to_pil(svg_data, output_size):
    """Converts SVG string data to a PIL Image object."""
    if not svg_data:
        return Image.new('RGBA', output_size, (0,0,0,0))
    png_data = cairosvg.svg2png(bytestring=svg_data.encode('utf-8'), output_width=output_size[0], output_height=output_size[1])
    return Image.open(io.BytesIO(png_data))

def draw_perspective_grid(draw):
    """
    Draws an enhanced perspective grid directly onto the canvas,
    with improved visibility and more dynamic perspective.
    """
    center_x = WIDTH / 2
    horizon_y = 110  # Slightly lower vanishing point for better perspective

    # Draw a subtle horizon line
    draw.line([(0, horizon_y), (WIDTH, horizon_y)], fill=COLOR_GRID, width=1)

    # Vertical lines converging towards the center
    for i in range(1, 24):  # More lines for better density
        # Left side
        x_top_l = center_x - i * 7
        x_bottom_l = center_x - i * 45
        draw.line([(x_top_l, horizon_y), (x_bottom_l, HEIGHT)], fill=COLOR_GRID, width=2)
        # Right side
        x_top_r = center_x + i * 7
        x_bottom_r = center_x + i * 45
        draw.line([(x_top_r, horizon_y), (x_bottom_r, HEIGHT)], fill=COLOR_GRID, width=2)

    # Horizontal lines getting closer together towards the horizon
    for i in range(1, 12):  # More horizontal lines
        y = horizon_y + (i**2) * 4  # More dramatic perspective curve
        if y > HEIGHT: break

        # Calculate the width of the horizontal line at this y-coordinate
        w_ratio = (y - horizon_y) / (HEIGHT - horizon_y)
        x_start = center_x - (7 + (45 - 7) * w_ratio) * 23
        x_end = center_x + (7 + (45 - 7) * w_ratio) * 23
        draw.line([(x_start, y), (x_end, y)], fill=COLOR_GRID, width=2)


def draw_animated_elements(img, draw, frame_number, stats, assets):
    """Draws all animated components for a given frame with enhanced visual effects."""
    # 1. Animated Folders - repositioned to fit within frame
    active_folder_index = (frame_number // (NUM_FRAMES // 4)) % 4
    for j in range(4):
        folder_img = assets['folder_active'] if j == active_folder_index else assets['folder_inactive']
        img.paste(folder_img, (590 + j * 45, 52), folder_img)  # Moved further left with reduced spacing

    # 2. Enhanced Laptop Screen Glare
    glare_progress = (frame_number % (NUM_FRAMES // 2)) / (NUM_FRAMES // 2)
    if frame_number < (NUM_FRAMES // 2):
        glare_x_start = 340 + (160 * glare_progress)
        glare_x_end = glare_x_start - 60
        # Create a wider, more visible glare effect
        glare_polygon = [(glare_x_start, 110), (glare_x_end, 200),
                          (glare_x_end - 20, 200), (glare_x_start - 60, 110)]
        draw.polygon(glare_polygon, fill=(255, 255, 255, 70))  # More visible glare

    # 3. Enhanced Animated Sparkles
    sparkle_positions = [(270, 120), (290, 190), (520, 110), (500, 180)]
    for i, (x, y) in enumerate(sparkle_positions):
        phase = (frame_number + i * 3) % NUM_FRAMES
        if phase < 4:  # Slightly longer sparkle duration
            size = 7  # Larger sparkles
            # Draw a more complex sparkle with diagonal lines
            draw.line([(x-size, y), (x+size, y)], fill=COLOR_SPARKLE, width=3)
            draw.line([(x, y-size), (x, y+size)], fill=COLOR_SPARKLE, width=3)
            draw.line([(x-size//2, y-size//2), (x+size//2, y+size//2)], fill=COLOR_SPARKLE, width=2)
            draw.line([(x+size//2, y-size//2), (x-size//2, y+size//2)], fill=COLOR_SPARKLE, width=2)

    # 4. Enhanced Animated Progress Bar
    bar_x, bar_y, bar_w, bar_h = 100, 280, 600, 30  # Taller progress bar
    progress_ratio = 1 - (1 - (frame_number + 1) / NUM_FRAMES)**2.5  # More dynamic easing
    current_frame_progress = stats['level_progress_percent'] * progress_ratio
    fill_w = (bar_w * current_frame_progress) / 100

    # Draw with improved visual style
    draw.rounded_rectangle([bar_x, bar_y, bar_x + bar_w, bar_y + bar_h], radius=15, fill=COLOR_BAR_BG)
    if fill_w > 1:
        draw.rounded_rectangle([bar_x, bar_y, bar_x + fill_w, bar_y + bar_h], radius=15, fill=COLOR_BAR_FILL)
    draw.rounded_rectangle([bar_x, bar_y, bar_x + bar_w, bar_y + bar_h], radius=15, outline=COLOR_TEXT, width=3)

# --- MAIN GENERATION SCRIPT ---

def main():
    """Main function to generate the animated GIF."""
    completed_tasks, total_tasks = parse_roadmap(ROADMAP_PATH)
    stats = calculate_stats(completed_tasks, total_tasks, LEVEL_THRESHOLDS)

    try:
        font_main = ImageFont.truetype(FONT_PATH, 42)  # Even larger main font
        font_sub = ImageFont.truetype(FONT_PATH, 28)   # Larger sub font
        font_small = ImageFont.truetype(FONT_PATH, 20) # Small font for minor details
    except IOError:
        print(f"Font file not found at '{FONT_PATH}'. Using default.")
        font_main, font_sub, font_small = ImageFont.load_default(), ImageFont.load_default(), ImageFont.load_default()

    # Pre-render all SVG assets with improved sizes
    try:
        assets = {
            'laptop': svg_to_pil(open(LAPTOP_SVG_PATH).read(), (280, 280)),  # Larger laptop
            'sword': svg_to_pil(open(SWORD_SVG_PATH).read(), (50, 50)),     # Larger sword
            'flag': svg_to_pil(open(FLAG_SVG_PATH).read(), (50, 50)),       # Larger flag
            'folder_inactive': svg_to_pil(colorize_svg(FOLDER_SVG_PATH, FOLDER_COLOR_INACTIVE), (45, 45)),
            'folder_active': svg_to_pil(colorize_svg(FOLDER_SVG_PATH, FOLDER_COLOR_ACTIVE), (45, 45))
        }
    except FileNotFoundError as e:
        print(f"Asset error: {e}. Please check your 'assets' directory.")
        return

    frames = []
    print("Generating frames...")
    for i in range(NUM_FRAMES):
        img = Image.new("RGBA", (WIDTH, HEIGHT), COLOR_BG)
        draw = ImageDraw.Draw(img)

        # Draw background grid first
        draw_perspective_grid(draw)

        # Paste laptop on top of the grid - centered and slightly higher
        img.paste(assets['laptop'], (WIDTH // 2 - 140, 35), assets['laptop'])

        # Draw all animated elements
        draw_animated_elements(img, draw, i, stats, assets)

        # Draw text with enhanced styling and positioning
        # Hunter name with shadow effect for better visibility
        hunter_text = f"HUNTER {HUNTER_NAME}"
        # Draw shadow
        draw.text((32, 22), hunter_text, font=font_main, fill="#333333")
        # Draw main text
        draw.text((30, 20), hunter_text, font=font_main, fill=COLOR_TEXT)

        # Rank and XP
        rank_text = f"RANK-{stats['rank']} {stats['xp']} XP"
        draw.text((32, 72), rank_text, font=font_sub, fill="#333333") # Shadow
        draw.text((30, 70), rank_text, font=font_sub, fill=COLOR_TEXT)

        # Project name with right alignment and shadow
        proj_name_bbox = draw.textbbox((0, 0), PROJECT_NAME, font=font_main)
        proj_name_width = proj_name_bbox[2] - proj_name_bbox[0]
        # Shadow
        draw.text((WIDTH - proj_name_width - 28, 22), PROJECT_NAME, font=font_main, fill="#333333")
        # Main text
        draw.text((WIDTH - proj_name_width - 30, 20), PROJECT_NAME, font=font_main, fill=COLOR_TEXT)

        # Level indicators with enhanced styling
        draw.text((90, 235), f"LEVEL {stats['level']}", font=font_sub, fill=COLOR_TEXT)
        draw.text((600, 235), f"LEVEL {stats['next_level']}", font=font_sub, fill=COLOR_TEXT)

        # Paste icons with improved positions and sizes
        bar_x, bar_y, bar_w = 100, 280, 600
        img.paste(assets['sword'], (bar_x - 70, bar_y - 15), assets['sword'])
        img.paste(assets['flag'], (bar_x + bar_w + 20, bar_y - 15), assets['flag'])

        frames.append(img)

    output_path = "progress_card_animated.gif"
    frames[0].save(
        output_path, save_all=True, append_images=frames[1:],
        duration=DURATION, loop=0, disposal=2
    )
    print(f"Successfully generated animated GIF: {output_path}")

if __name__ == "__main__":
    main()
