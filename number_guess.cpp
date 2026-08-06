#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int number = rand() % 100 + 1;
    int guess, attempts = 0;

    cout << "===== Number Guessing Game =====" << endl;
    cout << "Guess a number between 1 and 100" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > number)
            cout << "Too High!" << endl;
        else if (guess < number)
            cout << "Too Low!" << endl;
        else
            cout << "Congratulations! You guessed it in "
                 << attempts << " attempts." << endl;

    } while (guess != number);

    int score = 100 - (attempts - 1) * 10;
    if (score < 0)
        score = 0;

    cout << "Your Score: " << score << "/100" << endl;

    char choice;
    cout << "Play Again? (y/n): ";
    cin >> choice;

    cout << "Thank you for playing!" << endl;

    return 0;
}