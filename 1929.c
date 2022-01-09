#include <stdio.h>

int main(void)
{
    int primes[1000001] = {0};
    primes[1] = 1;

    int start, end;
    scanf("%d %d", &start, &end);

    int count, mul;
    for (count = 2; count * count <= end; count++)
    {
        for (mul = 2; count * mul <= end; mul++)
            primes[count * mul] = 1;
    }

    for (count = start; count <= end; count++)
        if (primes[count] == 0)
            printf("%d\n", count);
}
