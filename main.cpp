#include <iostream>

using namespace std;

const int ROW = 8;
const int COLUMN = 6;
const int GRID = 42;

const int COL_OFFSET = 5; //where it maximum it should be checking for the win con to avoid the ghost win
const int ROW_OFFSET = 3; //where it maximum it should be checking for the win con in the rows to not dip into different rows

const char PLAYER_1 = 'X';
const char PLAYER_2 = 'O';



bool winCon(char grid[][COLUMN]){
  for (int i = 0; i < ROW; i++){
    for (int j = 0; j < COLUMN; j++){
      if (i < COL_OFFSET && grid[i][j] == PLAYER_1 && grid[i][j] == grid[i+1][j] && grid[i][j] == grid[i+2][j] && grid[i][j] == grid[i+3][j]) {
        cout << "Four in a column Player One wins!" << endl;
        return true;
      } else if (i < COL_OFFSET && grid[i][j] == PLAYER_2 && grid[i][j] == grid[i+1][j] && grid[i][j] == grid[i+2][j] && grid[i][j] == grid[i+3][j]){
        cout << "Four in a column Player Two wins!" << endl;
        return true;
      }
      if (j < ROW_OFFSET && grid[i][j] == PLAYER_1 && grid[i][j] == grid[i][j+1] && grid[i][j] == grid[i][j+2] && grid[i][j] == grid[i][j+3]) {
        cout << "Four in a row Player One wins!" << endl;
        return true;
      } else if (j < ROW_OFFSET && grid[i][j] == PLAYER_2 && grid[i][j] == grid[i][j+1] && grid[i][j] == grid[i][j+2] && grid[i][j] == grid[i][j+3]){
        cout << "Four in a row Player Two wins!" << endl;
        return true;
      }
    }
  }
  return false;
}
//See constants to know ROW_OFFSET & COL_OFFSET


void print (char board [][COLUMN]){
  for (int i = 0; i < ROW; i++){
    for (int j = 0; j < COLUMN; j++){
      cout << board[i][j];
    }
    cout << endl;
  } 
  cout << endl;
}
//print board

bool valid(char board[][COLUMN], int x){
  if (x > 6) {
    cout << endl <<  "\t" << "So close try a number that's 6 or less. Please try again." << endl << endl;
    return false;
  }
  if (x < 1) {
    cout << endl <<  "\t" << "It can't be zero and it must be a positive number. Please try again." << endl << endl;
    return false;
  }
  if (board[0][x-1] != '-'){
    cout << endl << "\t" << "That column is full. Please try again." << endl << endl;
    return false; //checks row 0, the top row if it is '-' for that column
  } 
  return true;
}


void input (char board[][COLUMN], char player) {
  int x;
  if (player == PLAYER_1){
    cout << "Player one's Turn" << endl << "Pick a row and column to place an X:" ;
  } else {
    cout << "Player two's Turn" << endl << "Pick a row and column to place an O:" ;
  }
  cin >> x;
  bool test = valid(board, x);
  if (test == true){
    for (int i  = 0; i < ROW+1; i++){
      for (int j = 0; j < COLUMN; j++){
        if (board[i][x-1] != '-' && board[i-1][x-1] == '-'){
          board[i-1][x-1] = player;
        } 
        if (board[8][x-1] == '-'){
          board[8][x-1] = player;
            break;
        }
      }
    } 
  }  else {
    input(board, player);
  }
}


int main() {

  char connectFour[ROW+1][COLUMN] = {{'-', '-', '-','-', '-','-'}, {'-', '-', '-','-', '-','-'}, {'-', '-', '-','-', '-','-'}, {'-', '-', '-','-', '-','-'}, {'-', '-', '-','-', '-','-'}, {'-', '-', '-','-', '-','-'}, {'-', '-', '-','-', '-','-'}, {'-', '-', '-','-', '-','-'}, {'-', '-', '-','-', '-','-'}};

  print(connectFour);
  cout << endl << endl;

  char currentPlayer = PLAYER_1;

  for (int i = 0; i < GRID; i++){
    input(connectFour, currentPlayer);
    print(connectFour);
    if (currentPlayer == PLAYER_1){
      currentPlayer = PLAYER_2;
    } else {
      currentPlayer = PLAYER_1;
    }
    if (winCon(connectFour) == true){
      break;
    }
    cout << endl;
    if (i == GRID) {
      cout << "Well that's a tie, press run to play again." << endl;
    }
  }
  return 0; 
} 
