#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int sum = 0;

    int length;
    scanf("%d", &length);

    char *nums = (char *)malloc(length);
    scanf("%s", nums);

    int count;
    for (count = 0; count < length; count++)
        sum += nums[count] - '0';

    printf("%d\n", sum);
}