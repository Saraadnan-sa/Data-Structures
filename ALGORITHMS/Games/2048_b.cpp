#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

const int BOARD_SIZE = 4;

void printBoard(const  vector< vector<int>>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
             cout << board[i][j] << " ";
        }
         cout <<  endl;
    }
     cout <<  endl;
}

bool is2048Reached(const  vector< vector<int>>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == 2048) {
                return true;
            }
        }
    }
    return false;
}

bool isMoveValid(const  vector< vector<int>>& board, int row, int col, int value) {
    return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == 0);
}
void fillBoard(vector<vector<int>>& board) {
    if (is2048Reached(board)) {
        return;
    }

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == 0) {
                // Try placing a 2
                board[i][j] = 2;
                fillBoard(board);
                if (is2048Reached(board)) {
                    return;
                }

                // Backtrack
                board[i][j] = 0;

                // Try placing a 4
                board[i][j] = 4;
                fillBoard(board);
                if (is2048Reached(board)) {
                    return;
                }

                // Backtrack
                board[i][j] = 0;
            }
        }
    }
}

int main() {
     vector< vector<int>> board(BOARD_SIZE,  vector<int>(BOARD_SIZE, 0));
cout<<"START";
    fillBoard(board);

     cout << "Final Board:" <<  endl;
    printBoard(board);

    return 0;
}
