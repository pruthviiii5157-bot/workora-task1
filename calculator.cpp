#include <iostream>
using namespace std;

int main() {
    int choice;
    double a, b;

    do {
        cout << "\n===== Calculator =====\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Modulus\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice >= 1 && choice <= 5) {
            cout << "Enter two numbers: ";
            cin >> a >> b;
        }

        switch(choice) {
            case 1:
                cout << "Result = " << a + b;
                break;
            case 2:
                cout << "Result = " << a - b;
                break;
            case 3:
                cout << "Result = " << a * b;
                break;
            case 4:
                if(b != 0)
                    cout << "Result = " << a / b;
                else
                    cout << "Division by zero is not allowed.";
                break;
            case 5:
                cout << "Result = " << (int)a % (int)b;
                break;
            case 6:
                cout << "Thank You!";
                break;
            default:
                cout << "Invalid choice.";
        }

    } while(choice != 6);

    return 0;
}

