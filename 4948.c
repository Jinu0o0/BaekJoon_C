#include <stdio.h>

int primeCount(int num);

int main(void)
{
    int num;
    while (scanf("%d", &num) && num != 0)
        printf("%d\n", primeCount(num));
}

int primeCount(int num)
{
    int primes[300000] = {0};
    primes[1] = 1;

    int count, mul;
    for (count = 2; count * count <= 2 * num; count++)
    {
        for (mul = 2; count * mul <= 2 * num; mul++)
            primes[count * mul] = 1;
    }

    int check = 0;
    for (count = num + 1; count <= 2 * num; count++)
        if (primes[count] == 0)
            check++;

    return check;
}