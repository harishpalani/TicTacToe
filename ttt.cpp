/**
 * Tic Tac Toe
 * 
 * OVERVIEW
 * Create a tic-tac-toe game using the command line.
 * 
 * INTERFACE
 * Output the tic-tac-toe grid in the command line.  Input your move on the command line.  Keep track of how many times X wins instead O wins.
 * 
 * IMPLEMENTATION
 * Use a grid with letters and numbers to allow the user to enter a move.  Represent it internally with a two dimensional array. (10 points)
 * Have the user enter a move, check to see if the move is legal, and enter the move if it is legal.  (10 points)  Start with X.  After each move, check to see if the board contains a win or a tie.  
 * Reset the board and show winning totals if they win/tie.  (10 points)  Then redraw the board.
 * 
 * Comment your code! (5 points)
 * 
 * @author Harish Palani
 * @version 1.0
 */

#include <iostream> 
#include <string>

using namespace std;

void print(int BLANK, int O_MOVE, int X_MOVE, int(*pboard)[3]);
void reset(int BLANK, int(*pboard)[3]);
bool check_win(int player, int(*pboard)[3]);
bool check_tie(int BLANK, int(*pboard)[3]);
int play_game(int BLANK, int O_MOVE, int X_MOVE, int(*pboard)[3], int *pcounter);
void start(int BLANK, int O_MOVE, int X_MOVE, int(*pboard)[3], int *pcounter);

int main() {
  int BLANK = 0;
  int X_MOVE = 1;
  int O_MOVE = 2;
  int board[3][3];
  int(*pboard)[3] = board;
  int counter[3];
  
  for (int i = 0; i < 3; i++) {
    counter[i] = 0;
  }
  
  int *pcounter = counter;
  start(BLANK, O_MOVE, X_MOVE, pboard, pcounter);
  return 0;
}

// Methods //
int play_game(int BLANK, int O_MOVE, int X_MOVE, int(*pboard)[3], int *pcounter) {
  int O_TURN = 2;
  int X_TURN = 1;
  int turn = X_TURN;
  string input;
  
  print(BLANK, O_MOVE, X_MOVE, pboard);
  
  while (!check_win(X_MOVE, pboard) && !check_win(O_MOVE, pboard) && !check_tie(BLANK, pboard)) {
    cin >> input;
    
    if (input.length() != 2) {
      cout << "Please enter a letter followed by a number." << endl;
    } else if (input.at(0) != 'a' && input.at(0) != 'b' && input.at(0) != 'c') {
      cout << "The row value must be a, b, or c." << endl;
    } else if (input.at(1) != '1' && input.at(1) != '2' && input.at(1) != '3') {
      cout << "The column value must be 1, 2, or 3." << endl;
    } else {
      int row;
      if (input.at(0) == 'a') {
        row = 0;
      } else if (input.at(0) == 'b') {
        row = 1;
      } else if (input.at(0) == 'c') {
        row = 2;
      }
      
      int column;
      if (input.at(1) == '1') {
        column = 0;
      } else if (input.at(1) == '2') {
        column = 1;
      } else if (input.at(1) == '3') {
        column = 2;
      }
      
      if (pboard[row][column] == BLANK) {
        if (turn == X_TURN) {
          pboard[row][column] = X_MOVE;
          turn = O_TURN;
          print(BLANK, O_MOVE, X_MOVE, pboard);
        } else if (turn == O_TURN) {
          pboard[row][column] = O_MOVE;
          turn = X_TURN;
          print(BLANK, O_MOVE, X_MOVE, pboard);
        }
      } else {
        cout << "There is already a piece there. Choose another spot." << endl;
        print(BLANK, O_MOVE, X_MOVE, pboard);
      }
    }
    
    if (check_tie(BLANK, pboard)) {
      pcounter[0]++;

      int t = pcounter[0];
      int o = pcounter[1];
      int x = pcounter[2];
      cout << "\nIt's a tie!\n" << endl;
      
      cout << "WIN TOTALS" << endl;
      cout << "X: " << x << " wins" << " // " << "O: " << o << " wins" << " // " << "Ties: " << t << " ties\n" << endl;
    }
    
    if (check_win(O_MOVE, pboard)) {
      pcounter[1]++;

      int t = pcounter[0];
      int o = pcounter[1];
      int x = pcounter[2];
      cout << "\nO wins!\n" << endl;
      
      cout << "WIN TOTALS" << endl;
      cout << "X: " << x << " wins" << " // " << "O: " << o << " wins" << " // " << "Ties: " << t << " ties\n" << endl;
    }

    if (check_win(X_MOVE, pboard)) {
      pcounter[2]++;

      int t = pcounter[0];
      int o = pcounter[1];
      int x = pcounter[2];
      cout << "\nX wins!\n" << endl;
      
      cout << "WIN TOTALS" << endl;
      cout << "X: " << x << " wins" << " // " << "O: " << o << " wins" << " // " << "Ties: " << t << " ties\n" << endl;
    }
  }
}

void start(int BLANK, int O_MOVE, int X_MOVE, int(*pboard)[3], int *pcounter) {
  bool looper = true;
  char response = 0;
  while (looper) {
    cout << "Are you ready? (y / n)" << endl;
    cin >> response;
    if (response == 'n' || response == 'N') {
      cout << "Thanks for playing!";
      looper = false;
      return;
    }
    if (response == 'Y' || response == 'y') {
      reset(BLANK, pboard);
      play_game(BLANK, O_MOVE, X_MOVE, pboard, pcounter);
    } else {
      cout << "Please enter 'y' or 'n'." << endl;
    }
  }
}

bool check_win(int player, int(*pboard)[3]) {
  if (pboard[0][0] == player && pboard[0][1] == player && pboard[0][2] == player) {
    return true;
  }
  if (pboard[1][0] == player && pboard[1][1] == player && pboard[1][2] == player) {
    return true;
  }
  if (pboard[2][0] == player && pboard[2][1] == player && pboard[2][2] == player) {
    return true;
  }
  if (pboard[0][0] == player && pboard[1][0] == player && pboard[2][0] == player) {
    return true;
  }
  if (pboard[0][1] == player && pboard[1][1] == player && pboard[2][1] == player) {
    return true;
  }
  if (pboard[0][2] == player && pboard[1][2] == player && pboard[2][2] == player) {
    return true;
  }
  if (pboard[0][0] == player && pboard[1][1] == player && pboard[2][2] == player) {
    return true;
  }
  if (pboard[2][0] == player && pboard[1][1] == player && pboard[0][2] == player) {
    return true;
  }
    
  return false;
}

bool check_tie(int BLANK, int(*pboard)[3]) {
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      if (pboard[row][column] == BLANK) {
        return false;
      }
    }
  }
  return true;
}

void reset(int BLANK, int(*pboard)[3]) {
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      pboard[row][column] = BLANK;
    }
  }
}

void print(int BLANK, int O_MOVE, int X_MOVE, int(*pboard)[3]) {
  cout << "\t1\t2\t3" << endl;
  for (int row = 0; row < 3; row++) {
    if (row == 0) {
      cout << "a\t";
    }
    if (row == 1) {
      cout << "b\t";
    }
    if (row == 2) {
      cout << "c\t";
    }
    
    for (int column = 0; column < 3; column++) {
      if (pboard[row][column] == BLANK) {
        cout << "\t";
      }
      if (pboard[row][column] == X_MOVE) {
        cout << "X\t";
      }
      if (pboard[row][column] == O_MOVE) {
        cout << "O\t";
      }
      if (column == 2) {
        cout << endl;
      }
    }
  }
}