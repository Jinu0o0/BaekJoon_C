#include <stdio.h>
#include <stdlib.h>

int maxValue(int *cards, int total, int value);

int main(void)
{
    int total, value;
    scanf("%d %d", &total, &value);

    int *cards = (int *)malloc(total * sizeof(int));

    int count;
    for (count = 0; count < total; count++)
        scanf("%d", cards + count);

    printf("%d\n", maxValue(cards, total, value));

    free(cards);
}

int maxValue(int *cards, int total, int value)
{
    int sum1, sum2, sum3, max = 0;

    int first, second, third;
    for (first = 0; first < total - 2; first++)
    {
        sum1 = cards[first];
        if (sum1 >= value)
            continue;
        for (second = first + 1; second < total - 1; second++)
        {
            sum2 = sum1 + cards[second];
            if (sum2 >= value)
                continue;
            for (third = second + 1; third < total; third++)
            {
                sum3 = sum2 + cards[third];
                if (sum3 <= value && sum3 > max)
                    max = sum3;
            }
        }
    }

    return max;
}