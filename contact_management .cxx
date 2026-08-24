#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
    string address;
};

vector<Contact> contacts;

void saveContacts() {
    ofstream file("contacts.txt");

    for (const auto &c : contacts) {
        file << c.name << endl;
        file << c.phone << endl;
        file << c.email << endl;
        file << c.address << endl;
    }

    file.close();
}

void loadContacts() {
    ifstream file("contacts.txt");

    Contact c;

    while (getline(file, c.name)) {
        getline(file, c.phone);
        getline(file, c.email);
        getline(file, c.address);

        contacts.push_back(c);
    }

    file.close();
}

void addContact() {
    Contact c;

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, c.name);

    cout << "Enter Phone: ";
    getline(cin, c.phone);

    cout << "Enter Email: ";
    getline(cin, c.email);

    cout << "Enter Address: ";
    getline(cin, c.address);

    contacts.push_back(c);
    saveContacts();

    cout << "\nContact added successfully!\n";
}

void displayContacts() {
    if (contacts.empty()) {
        cout << "\nNo contacts available.\n";
        return;
    }

    cout << "\n===== All Contacts =====\n";

    for (const auto &c : contacts) {
        cout << "\nName: " << c.name;
        cout << "\nPhone: " << c.phone;
        cout << "\nEmail: " << c.email;
        cout << "\nAddress: " << c.address << endl;
    }
}

void searchContact() {
    string search;
    bool found = false;

    cin.ignore();

    cout << "Enter name or phone to search: ";
    getline(cin, search);

    for (const auto &c : contacts) {
        if (c.name == search || c.phone == search) {
            cout << "\nContact Found!\n";
            cout << "Name: " << c.name << endl;
            cout << "Phone: " << c.phone << endl;
            cout << "Email: " << c.email << endl;
            cout << "Address: " << c.address << endl;

            found = true;
        }
    }

    if (!found)
        cout << "\nContact not found.\n";
}

int main() {
    loadContacts();

    int choice;

    do {
        cout << "\n===== Contact Management System =====\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact();
                break;

            case 2:
                displayContacts();
                break;

            case 3:
                searchContact();
                break;

            case 4:
                saveContacts();
                cout << "Contacts saved. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}