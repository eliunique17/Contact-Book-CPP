#ifndef CONTACT_H
#define CONTACT_H

#include <string>
using namespace std;

class Contact {
private:
    string name;
    string phone;
    string email;

public:
    // Constructor
    Contact(string n, string p, string e);

    // Getters
    string getName() const;
    string getPhone() const;
    string getEmail() const;

    // Setters
    void setPhone(string p);
    void setEmail(string e);

    // Display
    void display() const;
};

#endif
