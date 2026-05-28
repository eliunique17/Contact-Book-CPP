#include "Contact.h"
#include <iostream>
using namespace std;

// Constructor
Contact::Contact(string n, string p, string e) {
    name = n;
    phone = p;
    email = e;
}

// Getters
string Contact::getName() const {
    return name;
}

string Contact::getPhone() const {
    return phone;
}

string Contact::getEmail() const {
    return email;
}

// Setters
void Contact::setPhone(string p) {
    phone = p;
}

void Contact::setEmail(string e) {
    email = e;
}

// Display
void Contact::display() const {
    cout << "   Name : " << name << endl;
    cout << "   Phone: " << phone << endl;
    cout << "   Email: " << email << endl;
    cout << "   -------------------" << endl;
}
