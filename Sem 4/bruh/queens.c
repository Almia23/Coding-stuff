#include <stdio.h>
#include <stdlib.h>
int count = 1;
void printboard(int solutionNum, int n, int board[])
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

int placequeen(int row, int n, int board[])
{
    if (row == n)
    {
        printboard((count++), n, board);
        return 1;
    }
    int f = 0;
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
            f = placequeen(row + 1, n, board) || f;
        }
    }
    return f;
}
void nqueens(int n)
{
    int board[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = -1;
    }
    placequeen(0, n, board);
}
int main()
{
    int n;
    printf("Enter number of queens: ");
    scanf("%d", &n);
    nqueens(n);
    return 0;
}