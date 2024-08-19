#include <stdio.h>
#include <stdlib.h>

int count = 1;
void nqueens(int n);
int placeQueen(int row, int n, int board[]);
void printBoard(int solutionNum, int n, int board[]);

int main(void)
{
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    nqueens(n);
    return 0;
}

void nqueens(int n)
{
    int board[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = -1; // Initialize board
    }
    placeQueen(0, n, board);
}

int placeQueen(int row, int n, int board[])
{
    if (row == n)
    {
        printBoard((count)++, n, board);
        return 1;
    }
    int found = 0;
    for (int col = 0; col < n; col++)
    {
        int valid = 1;
        for (int i = 0; i < row; i++)
        {
            if (board[i] == col || abs(i - row) == abs(board[i] - col))
            {
                valid = 0;
                break;
            }
        }
        if (valid)
        {
            board[row] = col;
            found = placeQueen(row + 1, n, board) || found;
        }
    }
    return found;
}

void printBoard(int solutionNum, int n, int board[])
{
    printf("Solution %d:\n", solutionNum);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c ", (board[i] == j) ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}