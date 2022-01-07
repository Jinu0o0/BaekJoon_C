#include <stdio.h>

void printCompare(int num1, int num2);

int main(void)
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    printCompare(num1, num2);
}

void printCompare(int num1, int num2)
{
    if (num1 < num2)
        printf("<\n");
    else if (num1 > num2)
        printf(">\n");
    else
        printf("==\n");
}