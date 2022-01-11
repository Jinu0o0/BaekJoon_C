#include <stdio.h>
#include <stdlib.h>

#define INT32_MAX 1 << 31 - 1
#define INT32_MIN 1 << 31

struct result
{
    int max;
    int min;
};

struct result operateAll(int idx, int len, int res, int *nums, int *ops);

int main(void)
{
    int num;
    scanf("%d\n", &num);

    int *nums = (int *)malloc(num * sizeof(int));
    int *ops = (int *)malloc(4 * sizeof(int));

    int count;
    for (count = 0; count < num; count++)
        scanf("%d", nums + count);
    for (count = 0; count < 4; count++)
        scanf("%d", ops + count);

    struct result res = operateAll(1, num, nums[0], nums, ops);

    printf("%d\n%d\n", res.max, res.min);

    free(nums);
    free(ops);
}

struct result operateAll(int idx, int len, int res, int *nums, int *ops)
{
    struct result next;

    if (idx == len)
    {
        next.min = res;
        next.max = res;
        return next;
    }

    int count, min = INT32_MAX, max = INT32_MIN, before;
    for (count = 0; count < 4; count++)
        if (ops[count] != 0)
        {
            switch (count)
            {
            case 0:
                before = res + nums[idx];
                break;
            case 1:
                before = res - nums[idx];
                break;
            case 2:
                before = res * nums[idx];
                break;
            case 3:
                before = res / nums[idx];
                break;
            }

            ops[count]--;
            next = operateAll(idx + 1, len, before, nums, ops);
            ops[count]++;

            if (min > next.min)
                min = next.min;
            if (max < next.max)
                max = next.max;
        }

    next.min = min;
    next.max = max;
    return next;
}