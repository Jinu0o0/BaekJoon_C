#include <stdio.h>

double getNewAvg(int num);

int main(void)
{
    int num;
    scanf("%d", &num);

    double res = getNewAvg(num);
    printf("%lf\n", res);
}

double getNewAvg(int num)
{
    int sum = 0, max = 0;

    int count, score;
    for (count = 0; count < num; count++)
    {
        scanf("%d", &score);
        sum += score;
        if (max < score)
            max = score;
    }

    return (double)sum / num / max * 100;
}