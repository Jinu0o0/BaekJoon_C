#include <stdio.h>

int main(void)
{
    int nums[10001] = {
        0,
    };

    int length;
    scanf("%d", &length);

    int count, num;
    for (count = 0; count < length; count++)
    {
        scanf("%d", &num);
        nums[num]++;
    }

    int index;
    for (count = 0; count <= 10000; count++)
        for (index = 0; index < nums[count]; index++)
            printf("%d\n", count);
}