#include <stdio.h>

int dFun(int num);

int main(void)
{
    int nums[10001] = {
        0,
    };

    int count;
    for (count = 1; count <= 10000; count++)
        nums[dFun(count)]++;

    for (count = 1; count <= 10000; count++)
        if (nums[count] == 0)
            printf("%d\n", count);
}

int dFun(int num)
{
    int copy = num;
    while (copy)
    {
        num += copy % 10;
        copy /= 10;
    }

    return num > 10000 ? 0 : num;
}