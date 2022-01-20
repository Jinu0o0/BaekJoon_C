#include <stdio.h>
#include <stdlib.h>

int *cost;

int main(void)
{
    int num;
    scanf("%d", &num);

    cost = (int *)malloc((num + 1) * sizeof(int));

    int count;
    for (count = 1; count <= num; count++)
    {
        if (count == 1)
            cost[count] = 0;
        else
        {
            int min = 1 << 30;
            if (count % 2 == 0)
                if (min > 1 + cost[count / 2])
                    min = 1 + cost[count / 2];
            if (count % 3 == 0)
                if (min > 1 + cost[count / 3])
                    min = 1 + cost[count / 3];
            if (min > 1 + cost[count - 1])
                min = 1 + cost[count - 1];
            cost[count] = min;
        }
    }

    printf("%d\n", cost[num]);
    free(cost);
}