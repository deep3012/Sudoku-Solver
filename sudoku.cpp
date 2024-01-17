#include <iostream>
using namespace std;

const int N = 9;

// Function to check if a number can be placed at the given position
bool isSafe(int board[N][N], int row, int col, int num)
{
    // Check if the number is not present in the current row and column
    for (int x = 0; x < N; x++)
    {
        if (board[row][x] == num || board[x][col] == num)
        {
            return false;
        }
    }

    // Check if the number is not present in the 3x3 grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i + startRow][j + startCol] == num)
            {
                return false;
            }
        }
    }

    return true;
}

// Function to print the Sudoku grid
void printBoard(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(int board[N][N])
{
    int row, col;

    // Find an empty cell
    bool isEmpty = false;
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            if (board[row][col] == 0)
            {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty)
        {
            break;
        }
    }

    // If there is no empty cell, the puzzle is solved
    if (!isEmpty)
    {
        return true;
    }

    // Try placing a number from 1 to 9 in the empty cell
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(board, row, col, num))
        {
            // Place the number if it is safe
            board[row][col] = num;

            // Recursively solve the rest of the puzzle
            if (solveSudoku(board))
            {
                return true;
            }

            // If placing the number doesn't lead to a solution, backtrack
            board[row][col] = 0;
        }
    }

    // No number can be placed at this cell, backtrack
    return false;
}

int main()
{
    int board[N][N];

    cout << "Enter the Sudoku puzzle (use 0 for empty cells):\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    if (solveSudoku(board))
    {
        cout << "\nSolved Sudoku:\n";
        printBoard(board);
    }
    else
    {
        cout << "\nNo solution exists.\n";
    }

    return 0;
}
