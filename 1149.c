#include <stdio.h>
#include <stdlib.h>

int *rs, *gs, *bs;

int getMinCost(int num);
void updateRCost(int num);
void updateGCost(int num);
void updateBCost(int num);

int main(void)
{
    int num;
    scanf("%d", &num);

    rs = (int *)malloc(num * sizeof(int));
    gs = (int *)malloc(num * sizeof(int));
    bs = (int *)malloc(num * sizeof(int));

    int count, r, g, b;
    for (count = 0; count < num; count++)
    {
        scanf("%d %d %d", &r, &g, &b);
        rs[count] = r;
        gs[count] = g;
        bs[count] = b;
    }
    printf("%d\n", getMinCost(num));

    free(rs);
    free(gs);
    free(bs);
}

int getMinCost(int num)
{
    int count;
    for (count = 1; count < num; count++)
    {
        updateRCost(count);
        updateGCost(count);
        updateBCost(count);
    }

    num--;
    if (rs[num] < gs[num])
    {
        if (rs[num] < bs[num])
            return rs[num];
        else
            return bs[num];
    }
    else
    {
        if (gs[num] < bs[num])
            return gs[num];
        else
            return bs[num];
    }
}

void updateRCost(int num)
{
    if (gs[num - 1] < bs[num - 1])
        rs[num] += gs[num - 1];
    else
        rs[num] += bs[num - 1];
}

void updateGCost(int num)
{
    if (bs[num - 1] < rs[num - 1])
        gs[num] += bs[num - 1];
    else
        gs[num] += rs[num - 1];
}

void updateBCost(int num)
{
    if (rs[num - 1] < gs[num - 1])
        bs[num] += rs[num - 1];
    else
        bs[num] += gs[num - 1];
}