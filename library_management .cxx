#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
using namespace std;

// Base class
class MediaItem {
protected:
    int id;
    string title;
    bool checkedOut;

public:
    MediaItem(int i, string t) {
        id = i;
        title = t;
        checkedOut = false;
    }

    virtual void display() const = 0;

    virtual double calculateFine(int overdueDays) const {
        return overdueDays * 2.0;
    }

    void checkout() {
        if (!checkedOut) {
            checkedOut = true;
            cout << "Item checked out successfully.\n";
        } else {
            cout << "Item is already checked out.\n";
        }
    }

    void returnItem(int overdueDays) {
        if (checkedOut) {
            checkedOut = false;

            double fine = calculateFine(overdueDays);

            cout << "Item returned successfully.\n";
            cout << "Fine: Rs. " << fine << endl;
        } else {
            cout << "Item was not checked out.\n";
        }
    }

    int getId() const {
        return id;
    }

    virtual ~MediaItem() {}
};

// Derived class: Book
class Book : public MediaItem {
private:
    string author;

public:
    Book(int i, string t, string a)
        : MediaItem(i, t), author(a) {}

    void display() const override {
        cout << "Book ID: " << id
             << " | Title: " << title
             << " | Author: " << author
             << " | Status: "
             << (checkedOut ? "Checked Out" : "Available")
             << endl;
    }

    double calculateFine(int overdueDays) const override {
        return overdueDays * 3.0;
    }
};

// Derived class: Journal
class Journal : public MediaItem {
private:
    int issueNumber;

public:
    Journal(int i, string t, int issue)
        : MediaItem(i, t), issueNumber(issue) {}

    void display() const override {
        cout << "Journal ID: " << id
             << " | Title: " << title
             << " | Issue: " << issueNumber
             << " | Status: "
             << (checkedOut ? "Checked Out" : "Available")
             << endl;
    }

    double calculateFine(int overdueDays) const override {
        return overdueDays * 2.0;
    }
};

// Save data to file
void saveToFile(const vector<unique_ptr<MediaItem>>& items) {
    ofstream file("library.txt");

    for (const auto& item : items) {
        file << item->getId() << endl;
    }

    file.close();
    cout << "Library data saved successfully.\n";
}

int main() {
    vector<unique_ptr<MediaItem>> library;

    library.push_back(
        make_unique<Book>(101, "C++ Programming", "Bjarne Stroustrup")
    );

    library.push_back(
        make_unique<Book>(102, "Data Structures", "Mark Allen")
    );

    library.push_back(
        make_unique<Journal>(201, "Computer Science Journal", 15)
    );

    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Display Items\n";
        cout << "2. Checkout Item\n";
        cout << "3. Return Item\n";
        cout << "4. Save to File\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\n--- Library Items ---\n";

            for (const auto& item : library) {
                item->display();
            }
        }

        else if (choice == 2) {
            int id;
            cout << "Enter Item ID: ";
            cin >> id;

            bool found = false;

            for (auto& item : library) {
                if (item->getId() == id) {
                    item->checkout();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Item not found.\n";
        }

        else if (choice == 3) {
            int id, days;

            cout << "Enter Item ID: ";
            cin >> id;

            cout << "Enter overdue days: ";
            cin >> days;

            bool found = false;

            for (auto& item : library) {
                if (item->getId() == id) {
                    item->returnItem(days);
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Item not found.\n";
        }

        else if (choice == 4) {
            saveToFile(library);
        }

        else if (choice == 5) {
            cout << "Thank you!\n";
        }

        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}