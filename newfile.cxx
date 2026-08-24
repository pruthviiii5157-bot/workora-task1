#include <iostream>
using namespace std;

void displayBoard(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | "
             << board[i][1] << " | "
             << board[i][2] << "\n";

        if (i < 2)
            cout << "---+---+---\n";
    }
    cout << "\n";
}

bool checkWin(char board[3][3], char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player &&
            board[1][j] == player &&
            board[2][j] == player)
            return true;
    }

    // Check diagonals
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

bool isDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    char player = 'X';
    int row, col;

    cout << "===== TIC-TAC-TOE GAME =====\n";

    while (true) {
        displayBoard(board);

        cout << "Player " << player << "'s turn\n";
        cout << "Enter row (1-3): ";
        cin >> row;

        cout << "Enter column (1-3): ";
        cin >> col;

        // Validate position
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            cout << "Invalid position! Try again.\n";
            continue;
        }

        // Check if position is already occupied
        if (board[row - 1][col - 1] != ' ') {
            cout << "Position already occupied! Try again.\n";
            continue;
        }

        // Place player's mark
        board[row - 1][col - 1] = player;

        // Check winner
        if (checkWin(board, player)) {
            displayBoard(board);
            cout << "Player " << player << " wins! 🎉\n";
            break;
        }

        // Check draw
        if (isDraw(board)) {
            displayBoard(board);
            cout << "Game Draw!\n";
            break;
        }

        // Switch player
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    return 0;
}