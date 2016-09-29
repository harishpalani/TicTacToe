#include <iostream>

using namespace std;

#define EMPTY 0;
#define X 1;
#define O 2;
#define X_TURN 0;
#define O_TURN 1;

void reset() {
    for (int row = 0; row < board.length; row++) {
        for (int column = 0; column < board[0].length; column++) {
            board[row][column] = EMPTY;
        }
    }
    System.out.println("\nGame #" + gameCount);
}

void printTotalsAndRestart() {
    System.out.println("WIN TOTALS");
    System.out.print("X: " + xWins + " wins" + " // ");
    System.out.print("O: " + oWins + " wins" + " // ");
    System.out.println("Ties: " + ties);
    gameCount++;
    reset();
    playGame();
}

bool checkWin(int player) {
    if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {
        return true;
    }
    if (board[1][0] == player && board[1][1] == player && board[1][2] == player) {
        return true;
    }
    if (board[2][0] == player && board[2][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][0] == player && board[1][0] == player && board[2][0] == player) {
        return true;
    }
    if (board[0][1] == player && board[1][1] == player && board[2][1] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][2] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[2][0] == player && board[1][1] == player && board[0][2] == player) {
        return true;
    }
    return false;
}

bool checkTie() {
    for (int row = 0; row < board.length; row++) {
        for (int column = 0; column < board[0].length; column++) {
            if (board[row][column] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

void checkCompletion() {
    if (checkWin(X) == true) {
        xWins++;
        printBoard();
        System.out.println("\nX wins!\n");
    } else if (checkWin(O) == true) {
        oWins++;
        printBoard();
        System.out.println("\nO wins!\n");
    } else if (checkTie() == true) {
        ties++;
        printBoard();
        System.out.println("\nIt's a tie!\n");
    }
    printTotalsAndRestart();
}

void oneGame() {
    printBoard();
    System.out.println();
	cout << "\n" << "Enter a row-column pair: " << endl;
    System.out.print("Enter a row-column pair: ");
    input = reader.nextLine();
    System.out.println();
    if (input.length() != 2) {
		cout << "\n" << "Please enter a letter followed by a number." << "\n" << endl;
    } else if (input.charAt(0) != 'a' && input.charAt(0) != 'b' && input.charAt(0) != 'c') {
		cout << "\n" << "The row value must be a, b, or c." << "\n" << endl;
        System.out.println();
    } else if (input.charAt(1) != '1' && input.charAt(1) != '2' && input.charAt(1) != '3') {
        cout << "\n" << "The column value must be 1, 2, or 3." << "\n" << endl;
    } else {
        int row = input.charAt(0) - 'a';
        int column = input.charAt(1) - '1';

        if (board[row][column] == EMPTY) {
            if (turn == X_TURN) {
                board[row][column] = X;
                turn = O_TURN;
            } else {
                board[row][column] = O;
                turn = X_TURN;
            }
        } else {
            cout << "There is already a piece there. Choose another spot." << endl;
        }
    }
}
    
void printBoard() {
    cout << " \t1\t2\t3" << endl;
    for (int row = 0; row < board.length; row++) {
        char[] output = (char) ('a' + row) + "\t";
        for (int column = 0; column < board[0].length; column++) {
            if (board[row][column] == EMPTY) {
                output += " \t";
            } else if (board[row][column] == X) {
                output += "X\t";
            } else if (board[row][column] == O) {
                output += "O\t";
            }
        }
        cout << output << endl;;
    }
}

void playGame() {
    turn = X_TURN;
    while (checkWin(X) == false && checkWin(O) == false && checkTie() == false) {
		oneGame();
    }
	checkCompletion();
}

int main() {
    playGame();
}