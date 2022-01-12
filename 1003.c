#include <stdio.h>

int count0[41];
int count1[41];

void setupCount(void);
void updateCount(int num);

int main(void)
{
    int test;
    scanf("%d", &test);

    setupCount();

    int count, num;
    for (count = 0; count < test; count++)
    {
        scanf("%d", &num);
        updateCount(num);
        printf("%d %d\n", count0[num], count1[num]);
    }
}

void setupCount(void)
{
    count0[0] = 1;
    count1[1] = 1;
}

void updateCount(int num)
{
    if (num < 2)
        return;
    if (count0[num] && count1[num])
        return;

    updateCount(num - 1);
    count0[num] = count0[num - 1] + count0[num - 2];
    count1[num] = count1[num - 1] + count1[num - 2];
}