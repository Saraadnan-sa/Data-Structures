#include <iostream>
#include <vector>

using namespace std;

void Const_board(vector<int> &board);
void user1_turn(vector<int> &board);
int minmax(vector<int> &board, int player);
void Comp_turn(vector<int> &board);
int analyze_board(vector<int> &board);

void Const_board(vector<int> &board)
{
    cout << "Current State of the Board: \n\n";
    for (int i = 0; i < 9; i++)
    {
        if ((i > 0) && (i % 3 == 0))
        {
            cout << "\n";
        }
        if (board[i] == 0)
        {
            cout << "_ ";
        }
        if (board[i] == -1)
        {
            cout << "X ";
        }
        if (board[i] == 1)
        {
            cout << "O ";
        }
    }
    cout << "\n\n";
}

void user1_turn(vector<int> &board)
{
    int pos;
    cout << "Enter X's position from [1,2,3....,9]: ";
    cin >> pos;
    if (board[pos - 1] != 0)
    {
        cout << "Wrong move!";
        exit(0);
    }
    board[pos - 1] = -1;
}

int minmax(vector<int> &board, int player)
{
    int x = analyze_board(board);
    if (x != 0)
    {
        return x * player;
    }
    int pos = -1;
    int value = -2;
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == 0)
        {
            board[i] = player;
            int score = -minmax(board, -player);
            board[i] = 0;
            if (score > value)
            {
                value = score;
                pos = i;
            }
        }
    }
    if (pos == -1)
    {
        return 0;
    }
    return value;
}

void Comp_turn(vector<int> &board)
{
    int pos = -1;
    int value = -2;
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == 0)
        {
            board[i] = 1;
            int score = -minmax(board, -1);
            board[i] = 0;
            if (score > value)
            {
                value = score;
                pos = i;
            }
        }
    }
    board[pos] = 1;
}

int analyze_board(vector<int> &board)
{
    vector<vector<int>> TicTacToe_Board = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
    for (int i = 0; i < 8; i++)
    {
        if (board[TicTacToe_Board[i][0]] != 0 && board[TicTacToe_Board[i][0]] == board[TicTacToe_Board[i][1]] && board[TicTacToe_Board[i][0]] == board[TicTacToe_Board[i][2]])
        {
            return board[TicTacToe_Board[i][0]];
        }
    }
    return 0;
}

int main()
{
    cout << "Single Player Mode: Computer (O) Vs. You (X)\n";
    vector<int> board = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    cout << "Computer: O Vs. You: X\n";
    int player;
    cout << "Enter to play 1st or 2nd: ";
    cin >> player;
    for (int i = 0; i < 9; i++)
    {
        if (analyze_board(board) != 0)
        {
            break;
        }
        if ((i + player) % 2 == 0)
        {
            Comp_turn(board);
        }
        else
        {
            Const_board(board);
            user1_turn(board);
        }
    }
    int x = analyze_board(board);
    if (x == 0)
    {
        Const_board(board);
        cout << "Draw!";
    }
    if (x == -1)
    {
        Const_board(board);
        cout << "Player X wins! Player O loses!";
    }
    if (x == 1)
    {
        Const_board(board);
        cout << "Player O wins! Player X loses!";
    }
    return 0;
}