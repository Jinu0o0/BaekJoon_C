#include <stdio.h>

long long int mul(int num1, int num2, int num3);

int main(void)
{
    int num1, num2, num3;
    scanf("%d %d %d", &num1, &num2, &num3);

    printf("%lld\n", mul(num1, num2, num3));
}

long long int mul(int num1, int num2, int num3)
{
    if (num2 == 0)
        return 1;
    if (num2 == 1)
        return num1 % num3;

    long long int res = mul(num1, num2 / 2, num3);
    res = res * res % num3;
    if (num2 % 2 == 1)
        res = res * num1 % num3;

    return res;
}