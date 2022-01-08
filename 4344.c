#include <stdio.h>
#include <stdlib.h>

double giveUpperAvg(void);

int main(void)
{
    int test;
    scanf("%d", &test);

    int count;
    for (count = 0; count < test; count++)
        printf("%.3lf%%\n", giveUpperAvg());
}

double giveUpperAvg(void)
{
    int sum = 0;

    int length;
    scanf("%d", &length);

    int *scores = (int *)malloc(length * sizeof(int));

    int count;
    for (count = 0; count < length; count++)
    {
        scanf("%d", scores + count);
        sum += scores[count];
    }

    int check = 0;
    double avg = sum / length;
    for (count = 0; count < length; count++)
        if (avg < scores[count])
            check++;

    return (double)check / length * 100;
}