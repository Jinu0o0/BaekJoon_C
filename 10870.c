#include <stdio.h>

int fibs[21];

int fib(int num);

int main(void)
{
    int num;
    scanf("%d", &num);

    printf("%d\n", fib(num));
}

int fib(int num)
{
    if (num == 0)
        return 0;
    else if (fibs[num])
        return fibs[num];
    else if (num == 1)
    {
        fibs[num] = 1;
        return fibs[num];
    }
    else
    {
        fibs[num] = fib(num - 1) + fib(num - 2);
        return fibs[num];
    }
}