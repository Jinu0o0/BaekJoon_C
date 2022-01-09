#include <stdio.h>
#include <stdlib.h>

void apartment(void);

int main(void)
{
    int test;
    scanf("%d", &test);

    int count;
    for (count = 0; count < test; count++)
        apartment();
}

void apartment(void)
{
    int row, col;
    scanf("%d %d", &row, &col);

    int *nums = (int *)malloc((col + 1) * sizeof(int));

    int r, c;
    for (r = 0; r <= row; r++)
    {
        for (c = 1; c <= col; c++)
        {
            if (r == 0)
                nums[c] = c;
            else if (c > 1)
                nums[c] += nums[c - 1];
        }
    }

    printf("%d\n", nums[col]);
}