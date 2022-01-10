#include <stdio.h>
#include <stdlib.h>

int repair(char **chess, int width, int height);

int main(void)
{
    int width, height;
    scanf("%d %d", &height, &width);

    int row, col;

    char **chess = (char **)malloc(height * sizeof(char *));
    for (row = 0; row < height; row++)
        *(chess + row) = (char *)malloc((width + 1) * sizeof(char));

    for (row = 0; row < height; row++)
        scanf("%s", *(chess + row));

    int min = 64, res;
    for (row = 0; row < height - 7; row++)
        for (col = 0; col < width - 7; col++)
        {
            res = repair(chess, row, col);
            if (min > res)
                min = res;
        }
    printf("%d\n", min);

    for (row = 0; row < height; row++)
        free(*(chess + row));
    free(chess);
}

int repair(char **chess, int width, int height)
{
    int res1 = 0, res2 = 0;
    int row, col;

    for (row = 0; row < 8; row++)
        for (col = 0; col < 8; col++)
        {
            if (chess[width + row][height + col] == ((row + col) % 2 ? 'W' : 'B'))
                res1++;
            else
                res2++;
        }

    return res1 < res2 ? res1 : res2;
}