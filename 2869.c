#include <stdio.h>

int roundUp(double num);

int main(void)
{
    long long int up, down, height;
    scanf("%lld %lld %lld", &up, &down, &height);

    long long int day = roundUp((double)(height - up) / (up - down)) + 1;
    printf("%lld\n", day);
}

int roundUp(double num)
{
    if (num - (int)num > 0)
        return (int)num + 1;
    else
        return (int)num;
}