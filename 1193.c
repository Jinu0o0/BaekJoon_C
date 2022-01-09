#include <stdio.h>

int main(void)
{
    int long long num;
    scanf("%lld", &num);

    int count;
    for (count = 2; num > (count - 1) * count / 2; count++)
    {
    }

    num -= (count - 2) * (count - 1) / 2;
    if (count % 2)
        printf("%lld/%lld\n", num, count - num);
    else
        printf("%lld/%lld\n", count - num, num);
}