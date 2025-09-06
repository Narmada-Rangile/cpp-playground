// Use parallel arrays to store names and phone numbers. Implement functions to add a new contact and search for a contact by name.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Contact
{
    string name;
    string phone_no;

    Contact(const string& s, const string& pn) : name(s), phone_no(pn) {}
};

// to display contacts
void display_contacts (const vector<Contact>& contacts)
{
    if (contacts.empty())
    {
        cout << "No contacts in the book." << endl;
        return;
    }

    cout << "\n===== CONTACT BOOK =====" << endl;
    cout << "No.\tName\t\t\tPhone Number" << endl;
    cout << "---\t----\t\t\t------------" << endl;

    int contact_no = 1;
    for (const Contact& contact : contacts)
    {
        cout << contact_no++ << ".\t" << contact.name << "\t\t\t" << contact.phone_no << endl;
    }
    cout << "===== ===== ===== =====" << endl;
}

// to add a new contact in the vector
void add_contact (vector<Contact> & contacts)
{
    string name, phone_no;
    cout << "Enter contact name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter phone number: ";
    cin.ignore();
    getline(cin, phone_no);

    const Contact new_contact(name, phone_no);

    contacts.push_back(new_contact);
    cout << "Contact added successfully!" << endl;
}

// to search for a contact
int search_contact (const vector<Contact>& contacts)
{
    if (contacts.empty())
    {
        cout << "No contacts to search in." << endl;
        return -1;
    }

    string search_name;
    cout << "Enter name to search: ";
    cin.ignore();
    getline(cin, search_name);

    int index = 0;
    for (const Contact& contact : contacts)
    {
        if (contact.name == search_name)
        {
            cout << "Contact Found!" << endl;
            cout << "Name: " << contact.name << endl;
            cout << "Phone No.: " << contact.phone_no << endl;
            return index;
        }
        index++;
    }

    cout << "Contact not found." << endl;
    return -1;
}

// to remove a contact
void remove_contact(vector<Contact>& contacts)
{
    if (contacts.empty())
    {
        cout << "No contacts to remove from." << endl;
        return;
    }

    int contact_no;
    cout << "Enter contact number to remove (1-" << contacts.size() << "): ";
    cin >> contact_no;

    if (contact_no < 1 || contact_no > static_cast<int>(contacts.size()))
    {
        cout << "Invalid contact number!" << endl;
        return;
    }

    contacts.erase(contacts.begin() + contact_no - 1);
    cout << "Contact removed successfully" << endl;
}

int main()
{
    vector<Contact> contacts;
    int choice;

    cout << "===== CONTACT BOOK MANAGER =====" << endl;

    do
    {
        cout << "\n1. ADD CONTACT" << endl;
        cout << "2. DISPLAY ALL CONTACTS" << endl;
        cout << "3. SEARCH CONTACT" << endl;
        cout << "4. REMOVE CONTACT" << endl;
        cout << "5. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            {
                add_contact(contacts);
                break;
            }
        case 2:
            {
                display_contacts(contacts);
                break;
            }
        case 3:
            {
                search_contact(contacts);
                break;
            }
        case 4:
            {
                display_contacts(contacts);
                remove_contact(contacts);
                break;
            }
        case 5:
            {
                cout << "See YA!" << endl;
                break;
            }
        default:
            cout << "Invalid Choice. Try Again!" << endl;
        }
    }
    while (choice != 5);
    return 0;
}
