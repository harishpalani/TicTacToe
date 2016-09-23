#include <iostream>

using namespace std;

#define EMPTY 0;
#define X 1;
#define O 2;
#define X_TURN 0;
#define O_TURN 1;

void printBoard(int** board) {
  cout << " \t1\t2\t3";
  for (int row = 0; row < (sizeof(board) / sizeof(board[0]); row++) {
    String output = (char) ('a' + row) + "\t";
    for (int column = 0; column < (sizeof(board[0] / sizeof(board[0][0]); column++) {
      if (board[row][column] == 0) {
	output += " \t";
      } else if (board[row][column] == 1) {
	output += "X\t";
      } else if (board[row][column] == 2) {
	output += "O\t";
      }
    }
    cout << output;
  }
}

void playGame() {

}

int main() {
  int board[3][3];
  int*[3] boardPtr = board;
  
  int turn = X_TURN;
  int xWins = 0;
  int ties = 0;
  int gameCount = 0;

  cout << "Tic Tac Toe - three in a row!\n";
  gameCount++;
  cout << "Game #" << gameCount;

  playGame();
}
