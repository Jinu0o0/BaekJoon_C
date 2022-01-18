#include <stdio.h>

int main(void)
{
    int score, sum = 0;

    int count;
    for (count = 0; count < 5; count++)
    {
        scanf("%d", &score);
        if (score < 40)
            sum += 40;
        else
            sum += score;
    }

    printf("%d\n", sum / 5);
}