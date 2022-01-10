#include <stdio.h>
#include <stdlib.h>

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

    for (count = 0; count < length; count++)
        printf("%d\n", nums[count]);

    free(nums);
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