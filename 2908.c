#include <stdio.h>

#define false 0
#define true 1

int back(int num);

int main(void)
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    num1 = back(num1);
    num2 = back(num2);

    if (num1 > num2)
        printf("%d\n", num1);
    else
        printf("%d\n", num2);
}

int back(int num)
{
    int new = 0;
    while (num)
    {
        new *= 10;
        new += num % 10;
        num /= 10;
    }

    return new;
}