#include <stdio.h>
#include <stdlib.h>

int *step;
int *stepCount;

void updateStep(int length);

int main(void)
{
    int length;
    scanf("%d", &length);

    int count;
    step = (int *)calloc((length + 1), sizeof(int));
    stepCount = (int *)calloc((length + 1), sizeof(int));
    for (count = 1; count <= length; count++)
        scanf("%d", step + count);

    updateStep(length);
    printf("%d\n", stepCount[length]);

    free(step);
    free(stepCount);
}

void updateStep(int length)
{
    int count;
    for (count = 1; count <= length; count++)
    {
        if (count == 1)
            stepCount[count] = step[count];
        else if (count == 2)
            stepCount[count] = stepCount[count - 1] + step[count];
        else
        {
            int beforeCount1 = step[count - 1] + stepCount[count - 3];
            int beforeCount2 = stepCount[count - 2];

            stepCount[count] = step[count];
            if (beforeCount1 > beforeCount2)
                stepCount[count] += beforeCount1;
            else
                stepCount[count] += beforeCount2;
        }
    }
}