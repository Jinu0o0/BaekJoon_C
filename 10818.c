#include <stdio.h>

int main(void)
{
    int min = 1000001, max = -1000001;

    int length;
    scanf("%d", &length);

    int count, num;
    for (count = 0; count < length; count++)
    {
        scanf("%d", &num);
        if (min > num)
            min = num;
        if (max < num)
            max = num;
    }

    printf("%d %d\n", min, max);
}