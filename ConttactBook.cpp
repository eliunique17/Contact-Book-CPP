#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>  // for system("cls") or system("clear")
using namespace std;

// ========== CONTACT CLASS ==========
class Contact {
private:
    string name;
    string phone;
    string email;

public:
    // Constructor
    Contact(string n, string p, string e) {
        name = n;
        phone = p;
        email = e;
    }

    // Getters
    string getName() const {
        return name;
    }

    string getPhone() const {
        return phone;
    }


    string getEmail() const {
        return email;
    }

    // Setters
    void setPhone(string p) {
        phone = p;
    }

    void setEmail(string e) {
        email = e;
    }

    // Display single contact
    void display() const {
        cout << "   Name : " << name << endl;
        cout << "   Phone: " << phone << endl;
        cout << "   Email: " << email << endl;
        cout << "   -------------------" << endl;
    }
};
// ========== CONTACT BOOK CLASS ==========
class ContactBook {
private:
    vector<Contact> contacts;
    string filename;

public:
    // Constructor
    ContactBook(string fname) {
        filename = fname;
        loadFromFile();
    }

    // Add contact
    void addContact(string name, string phone, string email) {
        Contact newContact(name, phone, email);
        contacts.push_back(newContact);
        cout << "\n✅ Contact added successfully!\n";
    }

    // View all contacts
    void viewAll() {
        if (contacts.empty()) {
            cout << "\n📭 No contacts found.\n";
            return;
        }

        cout << "\n========== ALL CONTACTS ==========\n";
        cout << "Total: " << contacts.size() << " contact(s)\n\n";

        for (int i = 0; i < contacts.size(); i++) {
            cout << "Contact #" << (i + 1) << ":\n";
            contacts[i].display();
        }
    }

    // Search contact by name
    void searchByName(string searchName) {
        bool found = false;

        for (int i = 0; i < contacts.size(); i++) {
            if (contacts[i].getName() == searchName) {
                cout << "\n🔍 Contact found:\n";
                contacts[i].display();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "\n❌ Contact \"" << searchName << "\" not found.\n";
        }
    }

    // Delete contact by name
    void deleteContact(string delName) {
        for (int i = 0; i < contacts.size(); i++) {
            if (contacts[i].getName() == delName) {
                contacts.erase(contacts.begin() + i);
                cout << "\n🗑️ Contact \"" << delName << "\" deleted successfully!\n";
                return;
            }
        }
        cout << "\n❌ Contact \"" << delName << "\" not found.\n";
    }

    // Edit contact
    void editContact(string editName) {
        for (int i = 0; i < contacts.size(); i++) {
            if (contacts[i].getName() == editName) {
                cout << "\n✏️ Editing: " << editName << endl;

                string newPhone, newEmail;
                cout << "   Enter new phone (or press Enter to keep): ";
                cin.ignore();
                getline(cin, newPhone);
                if (!newPhone.empty()) {
                    contacts[i].setPhone(newPhone);
                }

                cout << "   Enter new email (or press Enter to keep): ";
                getline(cin, newEmail);
                if (!newEmail.empty()) {
                    contacts[i].setEmail(newEmail);
                }

                cout << "\n✅ Contact updated successfully!\n";
                return;
            }
        }
        cout << "\n❌ Contact \"" << editName << "\" not found.\n";
    }

    // Save to file
    void saveToFile() {
        ofstream file(filename);

        if (!file) {
            cout << "\n⚠️ Error saving to file!\n";
            return;
        }

        for (int i = 0; i < contacts.size(); i++) {
            file << contacts[i].getName() << endl;
            file << contacts[i].getPhone() << endl;
            file << contacts[i].getEmail() << endl;
        }

        file.close();
        cout << "\n💾 Contacts saved to file!\n";
    }

    // Load from file
    void loadFromFile() {
        ifstream file(filename);

        if (!file) {
            cout << "📝 No existing save file. Starting fresh.\n";
            return;
        }

        string name, phone, email;
        while (getline(file, name)) {
            getline(file, phone);
            getline(file, email);
            contacts.push_back(Contact(name, phone, email));
        }

        file.close();

        if (!contacts.empty()) {
            cout << "📂 Loaded " << contacts.size() << " contact(s) from file.\n";
        }
    }
};
