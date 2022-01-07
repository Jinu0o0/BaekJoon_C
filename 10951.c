#include <stdio.h>

#define false 0
#define true 1

int add(void);

int main(void)
{
    while (add())
    {
    }
}

int add(void)
{
    int num1, num2;
    if (scanf("%d %d", &num1, &num2) == -1)
        return false;

    printf("%d\n", num1 + num2);
    return true;
}