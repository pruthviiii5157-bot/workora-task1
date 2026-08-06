#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Room {
public:
    int roomNo;
    string customer;
    bool booked;

    Room() {
        booked = false;
    }
};

int main() {
    Room r;
    int choice;

    do {
        cout << "\n===== Hotel Management System =====\n";
        cout << "1. Book Room\n";
        cout << "2. View Room\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter Room Number: ";
                cin >> r.roomNo;
                cout << "Enter Customer Name: ";
                cin >> r.customer;
                r.booked = true;

                {
                    ofstream file("hotel.txt");
                    file << r.roomNo << " " << r.customer << " " << r.booked;
                    file.close();
                }

                cout << "Room Booked Successfully!\n";
                break;

            case 2:
                {
                    ifstream file("hotel.txt");
                    if(file) {
                        file >> r.roomNo >> r.customer >> r.booked;
                        cout << "Room: " << r.roomNo << endl;
                        cout << "Customer: " << r.customer << endl;
                        cout << "Status: " << (r.booked ? "Booked" : "Available") << endl;
                    } else {
                        cout << "No booking found.\n";
                    }
                    file.close();
                }
                break;

            case 3:
                cout << "Thank You!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 3);

    return 0;
}