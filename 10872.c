#include <stdio.h>

int fac(int num);

int main(void)
{
    int num;
    scanf("%d", &num);
    printf("%d\n", fac(num));
}

int fac(int num)
{
    if (num == 0 || num == 1)
        return 1;
    else
        return num * fac(num - 1);
}