#include <stdio.h>

#define false 0
#define true 1

int checkDestoryNum(int num);

int main(void)
{
    int num;
    scanf("%d", &num);

    int count, check = 0;
    for (count = 666; check != num; count++)
        check += checkDestoryNum(count);

    printf("%d\n", count - 1);
}

int checkDestoryNum(int num)
{
    while (num >= 666)
    {
        if (num % 1000 == 666)
            return true;
        num /= 10;
    }

    return false;
}