#include <stdio.h>

int sum(int num);

int main(void)
{
    int num;
    scanf("%d", &num);

    int res = sum(num);
    printf("%d\n", res);
}

int sum(int num)
{
    int count, sum = 0;
    for (count = 1; count <= num; count++)
        sum += count;

    return sum;
}