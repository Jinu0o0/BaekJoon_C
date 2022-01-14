#include <stdio.h>

#define false 0
#define true 1

int findOnlyOne(int num);

int main(void)
{
    int num;
    while (scanf("%d", &num) != -1)
        printf("%d\n", findOnlyOne(num));
}

int findOnlyOne(int num)
{
    int mul = 1;
    int length = 1;
    while (true)
    {
        if (mul % num == 0)
            return length;
        mul = (mul % num) * 10 + 1;
        length++;
    }
}