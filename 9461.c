#include <stdio.h>

long long int triNums[101];

void initTriNums(void);
long long int updateTriNums(int um);

int main(void)
{
    int test;
    scanf("%d", &test);

    initTriNums();

    int count, num;
    for (count = 0; count < test; count++)
    {
        scanf("%d", &num);
        printf("%lld\n", updateTriNums(num));
    }
}

void initTriNums(void)
{
    triNums[1] = 1;
    triNums[2] = 1;
    triNums[3] = 1;
}

long long int updateTriNums(int num)
{
    if (triNums[num] == 0)
        triNums[num] = updateTriNums(num - 2) + updateTriNums(num - 3);

    return triNums[num];
}