#include <stdio.h>

void printQuadrant(int x, int y);

int main(void)
{
    int x, y;
    scanf("%d %d", &x, &y);

    printQuadrant(x, y);
}

void printQuadrant(int x, int y)
{
    if (x > 0)
    {
        if (y > 0)
            printf("1\n");
        else
            printf("4\n");
    }
    else
    {
        if (y > 0)
            printf("2\n");
        else
            printf("3\n");
    }
}