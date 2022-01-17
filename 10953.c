#include <stdio.h>

int sum(void);

int main(void)
{
    int test;
    scanf("%d", &test);

    int count;
    for (count = 0; count < test; count++)
        printf("%d\n", sum());
}

int sum(void)
{
    int num1, num2;
    scanf("%d, %d", &num1, &num2);
    return num1 + num2;
}