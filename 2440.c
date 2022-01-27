#include <stdio.h>

int main(void)
{
    int num;
    scanf("%d", &num);

    int row, col;
    for (row = 0; row < num; row++)
    {
        for (col = 0; col < num - row; col++)   
            printf("*");
        printf("\n");
    }
}