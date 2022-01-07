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
    scanf("%d %d", &num1, &num2);

    if (num1 == 0 && num2 == 0)
        return false;
    else
    {
        printf("%d\n", num1 + num2);
        return true;
    }
}