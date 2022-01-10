#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

int solve(int **board, int irow, int icol);
int checkFill(int **board, int row, int col, int fill);

int main(void)
{
    int count;
    int **board = (int **)calloc(9, sizeof(int *));
    for (count = 0; count < 9; count++)
        *(board + count) = (int *)calloc(9, sizeof(int));

    int row, col;
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            scanf("%d", &board[row][col]);

    solve(board, 0, 0);

    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
            printf("%d ", board[row][col]);
        printf("\n");
    }

    for (count = 0; count < 9; count++)
        free(*(board + count));
    free(board);
}

int solve(int **board, int irow, int icol)
{
    int row, col, fill;
    for (row = irow; row < 9; row++)
        for (col = (row == irow ? icol : 0); col < 9; col++)
            if (board[row][col] == 0)
            {
                for (fill = 1; fill <= 9; fill++)
                    if (checkFill(board, row, col, fill))
                    {
                        board[row][col] = fill;
                        if (solve(board, row, col))
                            return true;
                    }

                board[row][col] = 0;
                return false;
            }

    return true;
}

int checkFill(int **board, int row, int col, int fill)
{
    int check;

    for (check = 0; check < 9; check++)
    {
        if (check != row && board[check][col] == fill)
            return false;
        if (check != col && board[row][check] == fill)
            return false;
    }

    int srow, scol;
    for (srow = 0; srow < 3; srow++)
        for (scol = 0; scol < 3; scol++)
            if (row % 3 != srow && col % 3 != scol)
                if (board[row / 3 * 3 + srow][col / 3 * 3 + scol] == fill)
                    return false;

    return true;
}