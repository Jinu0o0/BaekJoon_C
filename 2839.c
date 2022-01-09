#include <stdio.h>

int main(void)
{
    int num;
    scanf("%d", &num);

    int res = 0;
    while (num)
    {
        if (num % 5 == 0)
        {
            num -= 5;
            res++;
        }
        else if (num % 3 == 0)
        {
            num -= 3;
            res++;
        }
        else if (num > 5)
        {
            num -= 5;
            res++;
        }
        else
        {
            res = -1;
            break;
        }
    }

    printf("%d\n", res);
}