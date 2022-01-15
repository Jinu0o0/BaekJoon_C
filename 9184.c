#include <stdio.h>

int wValue[21][21][21];

int wFunction(int num1, int num2, int num3);

int main(void)
{
    int num1, num2, num3;
    while (scanf("%d %d %d", &num1, &num2, &num3) != -1 && !(num1 == -1 && num2 == -1 && num3 == -1))
        printf("w(%d, %d, %d) = %d\n", num1, num2, num3, wFunction(num1, num2, num3));
}

int wFunction(int num1, int num2, int num3)
{
    if (num1 <= 0 || num2 <= 0 || num3 <= 0)
        return 1;

    if (num1 > 20 || num2 > 20 || num3 > 20)
        return wFunction(20, 20, 20);

    if (wValue[num1][num2][num3])
        return wValue[num1][num2][num3];

    if (num1 < num2 && num2 < num3)
    {
        wValue[num1][num2][num3] += wFunction(num1, num2, num3 - 1);
        wValue[num1][num2][num3] += wFunction(num1, num2 - 1, num3 - 1);
        wValue[num1][num2][num3] -= wFunction(num1, num2 - 1, num3);
        return wValue[num1][num2][num3];
    }
    else
    {
        wValue[num1][num2][num3] += wFunction(num1 - 1, num2, num3);
        wValue[num1][num2][num3] += wFunction(num1 - 1, num2 - 1, num3);
        wValue[num1][num2][num3] += wFunction(num1 - 1, num2, num3 - 1);
        wValue[num1][num2][num3] -= wFunction(num1 - 1, num2 - 1, num3 - 1);
        return wValue[num1][num2][num3];
    }
}