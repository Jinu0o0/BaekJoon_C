#include <stdio.h>

int primes[10001];

void initPrimes(void);
void twoPrimeSum(void);

int main(void)
{
    int test;
    scanf("%d", &test);

    initPrimes();

    int count;
    for (count = 0; count < test; count++)
        twoPrimeSum();
}

void initPrimes(void)
{
    primes[0] = 1;
    primes[1] = 1;

    int count, mul;
    for (count = 2; count * count <= 10000; count++)
        for (mul = 2; count * mul <= 10000; mul++)
            primes[count * mul] = 1;
}

void twoPrimeSum(void)
{
    int num;
    scanf("%d", &num);

    int count;
    for (count = num / 2; count >= 2; count--)
    {
        if (primes[count] == 0 && primes[num - count] == 0)
        {
            printf("%d %d\n", count, num - count);
            return;
        }
    }
}