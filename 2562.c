#include <stdio.h>

int main(void)
{
    int max_value = 0, max_index = 0;

    int count, num;
    for (count = 1; scanf("%d", &num) != -1; count++)
    {
        if (max_value < num)
        {
            max_value = num;
            max_index = count;
        }
    }

    printf("%d\n%d\n", max_value, max_index);
}