### **Purpose of Naming Conventions**

* To add **clarity** and **organization** to code \[[00:05](http://www.youtube.com/watch?v=LlzT3OBD5fA&t=5)\].
* To help understand what's happening in the code at a glance \[[00:22](http://www.youtube.com/watch?v=LlzT3OBD5fA&t=22)\].
* To provide more **information** and **context** to variables \[[01:03](http://www.youtube.com/watch?v=LlzT3OBD5fA&t=63)\].
* To improve **readability** and make it easier for developers to understand the code's meaning and purpose \[[05:52](http://www.youtube.com/watch?v=LlzT3OBD5fA&t=352)\].
* To help quickly identify the **scope** and **type** of variables (e.g., local, static, member) \[[09:47](http://www.youtube.com/watch?v=LlzT3OBD5fA&t=587)\].
* To aid in **optimizing** code by knowing where memory is located (static, class, local) \[[10:51](http://www.youtube.com/watch?v=LlzT3OBD5fA&t=651)\].
* To make code easier to **search** and **navigate** \[[14:40](http://www.youtube.com/watch?v=LlzT3OBD5fA&t=880)\].
* To indicate **implementation details** and internal variables \[[15:11](http://www.youtube.com/watch?v=LlzT3OBD5fA&t=911)\].

***

### **Common Prefixes and Their Meanings**

* `m_`: Typically used for **private member variables** within a class \[[00:37](http://www.youtube.com/watch?v=LlzT3OBD5fA&t=37)\].
* `s_`: Usually signifies **static variables**, including static class variables and non-class variables with internal linkage \[[00:44](http://www.youtube.com/watch?v=LlzT3OBD5fA&t=44)\].
* `g_`: Used for **global variables** \[[00:52](http://www.youtube.com/watch?v=LlzT3OBD5fA&t=52)\].
* `c_`: Can be used for **constants** \[[00:58](http://www.youtube.com/watch?v=LlzT3OBD5fA&t=58)\].
* Custom prefixes can be created, such as `p_` for parameter, `a_` for argument \[[01:03](http://www.youtube.com/watch?v=LlzT3OBD5fA&t=63)\], or `u_` for uniform variables in shading languages \[[01:15](http://www.youtube.com/watch?v=LlzT3OBD5fA&t=75)\].

***

### **Code Style for Prefixes**

* The presenter's preferred style is `letter_VariableName` where the variable name starts with a capital letter (PascalCase) \[[01:34](http://www.youtube.com/watch?v=LlzT3OBD5fA&t=94)\].
* Other styles include camelCase or snake\_case for the variable name, or omitting the underscore (e.g., `mVariableName`) \[[01:44](http://www.youtube.com/watch?v=LlzT3OBD5fA&t=104)\].

***

### **Illustrative Example of Readability Levels**

* **Obfuscated Code (Level 0):** Using meaningless single-letter variable names makes code extremely difficult to understand, even if the syntax is correct \[[03:51](http://www.youtube.com/watch?v=LlzT3OBD5fA&t=231)\].
* **Meaningful Names (Level 1):** Using descriptive names (e.g., `entity`, `projectile`, `fireProjectile`) significantly improves clarity and readability \[[06:55](http://www.youtube.com/watch?v=LlzT3OBD5fA&t=415)\].
* **Naming Conventions with Prefixes (Level 2):** Adding prefixes like `m_` and `s_` further enhances understanding by immediately indicating a variable's scope and type (e.g., `m_entities`, `s_projectilePool`) \[[12:41](http://www.youtube.com/watch?v=LlzT3OBD5fA&t=761)\]. This helps in identifying dependencies and potential multi-threading issues \[[08:55](http://www.youtube.com/watch?v=LlzT3OBD5fA&t=535)\].

***

### **Limitations of IDE Syntax Highlighting**

While some IDEs may color-code variables based on their scope, this is not always consistent or clear enough, and it doesn't work in environments like Git diff viewers \[[11:02](http://www.youtube.com/watch?v=LlzT3OBD5fA&t=662)\]. Naming conventions embedded in the variable name itself are permanent and universally visible \[[12:24](http://www.youtube.com/watch?v=LlzT3OBD5fA&t=744)\].
http://googleusercontent.com/youtube_content/10
