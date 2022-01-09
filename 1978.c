#include <stdio.h>

#define false 0
#define true 1

int isPrime(void);

int main(void)
{
    int test;
    scanf("%d", &test);

    int count, check = 0;
    for (count = 0; count < test; count++)
        if (isPrime())
            check++;

    printf("%d\n", check);
}

int isPrime(void)
{
    int num;
    scanf("%d", &num);

    if (num == 1)
        return false;

    int count;
    for (count = 2; count * count <= num; count++)
        if (num % count == 0)
            return false;

    return true;
}