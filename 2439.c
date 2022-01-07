#include <stdio.h>

void starSeq(int num);

int main(void)
{
    int num;
    scanf("%d", &num);

    starSeq(num);
}

void starSeq(int num)
{
    int row, col;
    for (row = 1; row <= num; row++)
    {
        for (col = 1; col <= num - row; col++)
            printf(" ");
        for (col = 1; col <= row; col++)
            printf("*");
        printf("\n");
    }
}