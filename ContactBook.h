#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include "Contact.h"
#include <vector>
#include <string>
using namespace std;

class ContactBook {
private:
    vector<Contact> contacts;
    string filename;

public:
    // Constructor
    ContactBook(string fname);

    // Core functions
    void addContact(string name, string phone, string email);
    void viewAll();
    void searchByName(string searchName);
    void deleteContact(string delName);
    void editContact(string editName);

    // File operations
    void saveToFile();
    void loadFromFile();
};

#endif
