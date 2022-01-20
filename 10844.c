#include <stdio.h>
#include <stdlib.h>

#define div 1000000000

int main(void)
{
    int length;
    scanf("%d", &length);

    int **stepNum, count;
    stepNum = (int **)malloc(length * sizeof(int *));
    for (count = 0; count < length; count++)
        *(stepNum + count) = (int *)malloc(10 * sizeof(int *));

    for (count = 0; count < 10; count++)
        stepNum[0][count] = 1;

    int other;
    for (count = 1; count < length; count++)
        for (other = 0; other < 10; other++)
        {
            if (other == 0)
                stepNum[count][other] = stepNum[count - 1][other + 1];
            else if (other == 9)
                stepNum[count][other] = stepNum[count - 1][other - 1];
            else
                stepNum[count][other] = (stepNum[count - 1][other - 1] % div + stepNum[count - 1][other + 1] % div) % div;
        }

    int sum = 0;
    for (count = 1; count < 10; count++)
    {
        sum += stepNum[length - 1][count];
        sum %= div;
    }

    printf("%d\n", sum);

    for (count = 0; count < length; count++)
        free(*(stepNum + count));
    free(stepNum);
}