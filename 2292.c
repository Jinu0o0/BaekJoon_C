#include <stdio.h>

int main(void)
{
    long long int num;
    scanf("%lld", &num);

    int count;
    for (count = 0; num > 3 * count * (count + 1) + 1; count++)
    {
    }

    printf("%d\n", count + 1);
}