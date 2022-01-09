#include <stdio.h>

int main(void)
{
    int num;
    scanf("%d", &num);

    int count;
    for (count = 2; num > 1;)
    {
        if (num % count == 0)
        {
            num /= count;
            printf("%d\n", count);
            continue;
        }
        count++;
    }
}