#include <stdio.h>

int decompose(int num);

int main(void)
{
    int res = 0;

    int num;
    scanf("%d", &num);

    int count;
    for (count = 1; count < num; count++)
        if (decompose(count) == num)
        {
            res = count;
            break;
        }

    printf("%d\n", res);
}

int decompose(int num)
{
    int new = num;

    while (num)
    {
        new += num % 10;
        num /= 10;
    }

    return new;
}