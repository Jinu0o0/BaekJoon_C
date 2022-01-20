#include <stdio.h>
#include <stdlib.h>

int *amouts;
int *amoutCounts;

int maxAmoutCount(int num);
int max(int num1, int num2);

int main(void)
{
    int num;
    scanf("%d", &num);

    amouts = (int *)calloc(num + 1, sizeof(int));
    amoutCounts = (int *)calloc(num + 1, sizeof(int));

    int count;
    for (count = 1; count <= num; count++)
        scanf("%d", amouts + count);

    printf("%d\n", maxAmoutCount(num));

    free(amouts);
    free(amoutCounts);
}

int maxAmoutCount(int num)
{
    int count;
    for (count = 1; count <= num; count++)
    {
        if (count == 1)
            amoutCounts[count] = amouts[count];
        else if (count == 2)
            amoutCounts[count] = amouts[count] + amouts[count - 1];
        else
            amoutCounts[count] = max(amouts[count] + amouts[count - 1] + amoutCounts[count - 3],
                                     max(amouts[count] + amoutCounts[count - 2], amoutCounts[count - 1]));
    }

    return amoutCounts[num];
}

int max(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}