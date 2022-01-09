#include <stdio.h>

void printRocket(void);

int main(void)
{
    int test;
    scanf("%d", &test);

    int count;
    for (count = 0; count < test; count++)
        printRocket();
}

void printRocket(void)
{
    long long int start, end, length;
    scanf("%lld %lld", &start, &end);
    length = end - start;

    long long int count, max_distance = 0;
    for (count = 0; max_distance < length; count++)
    {
        if (count % 2)
            max_distance += (count + 1) / 2;
        else
            max_distance += (count + 2) / 2;
    }

    printf("%lld\n", count);
}
