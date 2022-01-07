#include <stdio.h>

int numCycle(int num);

int main(void)
{
    int num;
    scanf("%d", &num);

    int res = numCycle(num);
    printf("%d\n", res);
}

int numCycle(int num)
{
    int new = num, new_ten, new_unit;
    int count = 0;

    do
    {
        new_ten = new % 10;

        if (new < 10)
            new *= 10;
        new_unit = (new / 10 + new % 10) % 10;

        new = new_ten * 10 + new_unit % 10;
        count++;
    } while (new != num);

    return count;
}
