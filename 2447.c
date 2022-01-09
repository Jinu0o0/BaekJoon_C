#include <stdio.h>

void printStar(int row, int col, int size);
void starRec(int size);

int main(void)
{
    int size;
    scanf("%d", &size);

    starRec(size);
}

void starRec(int size)
{
    int row, col;
    for (row = 0; row < size; row++)
    {
        for (col = 0; col < size; col++)
            printStar(row, col, size);
        printf("\n");
    }
}

void printStar(int row, int col, int size)
{
    if ((row / size) % 3 == 1 && (col / size) % 3 == 1)
        printf(" ");
    else if (size < 3)
        printf("*");
    else
        printStar(row, col, size / 3);
}