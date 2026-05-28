#include "ContactBook.h"
#include <iostream>
#include <cstdlib>  // for system()
using namespace std;

int main() {
    ContactBook myBook("contacts.txt");
    int choice;
    string name, phone, email;

    // Clear screen for better presentation
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    do {
        // Display menu
        cout << "\n==================================\n";
        cout << "       CONTACT BOOK MENU       \n";
        cout << "==================================\n";
        cout << "   1. Add Contact\n";
        cout << "   2. View All Contacts\n";
        cout << "   3. Search Contact\n";
        cout << "   4. Delete Contact\n";
        cout << "   5. Edit Contact\n";
        cout << "   6. Save & Exit\n";
        cout << "==================================\n";
        cout << "   Enter your choice (1-6): ";
        cin >> choice;

        switch(choice) {
            case 1:  // Add Contact
                cout << "\n--- ADD NEW CONTACT ---\n";
                cout << "   Name : ";
                cin.ignore();
                getline(cin, name);
                cout << "   Phone: ";
                getline(cin, phone);
                cout << "   Email: ";
                getline(cin, email);
                myBook.addContact(name, phone, email);
                break;

            case 2:  // View All
                myBook.viewAll();
                break;

            case 3:  // Search
                cout << "\n--- SEARCH CONTACT ---\n";
                cout << "   Enter name to search: ";
                cin.ignore();
                getline(cin, name);
                myBook.searchByName(name);
                break;

            case 4:  // Delete
                cout << "\n--- DELETE CONTACT ---\n";
                cout << "   Enter name to delete: ";
                cin.ignore();
                getline(cin, name);
                myBook.deleteContact(name);
                break;

            case 5:  // Edit
                cout << "\n--- EDIT CONTACT ---\n";
                cout << "   Enter name to edit: ";
                cin.ignore();
                getline(cin, name);
                myBook.editContact(name);
                break;

            case 6:  // Save & Exit
                myBook.saveToFile();
                cout << "\n👋 Goodbye!\n\n";
                break;

            default:
                cout << "\n❌ Invalid choice! Please enter 1-6.\n";
        }

    } while(choice != 6);

    return 0;
}
