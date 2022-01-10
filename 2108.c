#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

int avg(int *nums, int length);
int median(int *nums, int length);
int mode(int *nums, int length);
int range(int *nums, int length);
void merge(int *nums, int *temps, int start, int end);
void mergeSort(int *nums, int *temps, int start, int end);
void sort(int *nums, int length);

int main(void)
{
    int length;
    scanf("%d", &length);

    int *nums = (int *)malloc(length * sizeof(int));

    int count;
    for (count = 0; count < length; count++)
        scanf("%d", nums + count);

    sort(nums, length);

    printf("%d\n", avg(nums, length));
    printf("%d\n", median(nums, length));
    printf("%d\n", mode(nums, length));
    printf("%d\n", range(nums, length));

    free(nums);
}

int avg(int *nums, int length)
{
    long long int sum = 0;

    int count;
    for (count = 0; count < length; count++)
        sum += nums[count];

    if (sum > 0)
        return (int)((double)sum / length + 0.5);
    else
        return (int)((double)sum / length - 0.5);
}

int median(int *nums, int length)
{
    return nums[length / 2];
}

int mode(int *nums, int length)
{
    int counting[10000] = {0};

    int count;
    for (count = 0; count < length; count++)
        counting[nums[count] + 5000]++;

    int mode = 0, max = 0, multiple = false;
    for (count = 0; count < 10000; count++)
    {
        if (max < counting[count])
        {
            max = counting[count];
            mode = count;
            multiple = false;
        }
        else if (max == counting[count])
        {
            if (!multiple)
            {
                mode = count;
                multiple = true;
            }
        }
    }

    return mode - 5000;
}

int range(int *nums, int length)
{
    return nums[length - 1] - nums[0];
}

void sort(int *nums, int length)
{
    int *temps = (int *)malloc(length * sizeof(int));
    mergeSort(nums, temps, 0, length - 1);
    free(temps);
}

void mergeSort(int *nums, int *temps, int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;
    mergeSort(nums, temps, start, mid);
    mergeSort(nums, temps, mid + 1, end);
    merge(nums, temps, start, end);
}

void merge(int *nums, int *temps, int start, int end)
{
    int mid = (start + end) / 2;

    int start1 = start;
    int end1 = mid;
    int start2 = mid + 1;
    int end2 = end;
    int count = start;

    while (start1 <= end1 && start2 <= end2)
        if (nums[start1] < nums[start2])
            temps[count++] = nums[start1++];
        else
            temps[count++] = nums[start2++];

    while (start1 <= end1)
        temps[count++] = nums[start1++];

    while (start2 <= end2)
        temps[count++] = nums[start2++];

    for (count = start; count <= end; count++)
        nums[count] = temps[count];
}