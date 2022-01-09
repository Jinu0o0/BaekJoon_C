#include <stdio.h>

#define false 0
#define true 1

int isPrime(int num, int *primes);

int main(void)
{
    int primes[10001] = {0};

    int start, end;
    scanf("%d %d", &start, &end);

    int count, min = 0, sum = 0;
    for (count = 2; count <= end; count++)
    {
        if (isPrime(count, primes) && count >= start)
        {
            sum += count;
            if (min == 0)
                min = count;
        }
    }

    if (min)
        printf("%d\n%d\n", sum, min);
    else
        printf("-1\n");
}

int isPrime(int num, int *primes)
{
    int count;
    for (count = 0; primes[count] != 0; count++)
        if (num % primes[count] == 0)
            return false;

    primes[count] = num;
    return true;
}