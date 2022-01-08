#include <stdio.h>
#include <stdlib.h>

long long sum(int *a, int n);

int main(void)
{
    int length;
    scanf("%d", &length);

    int *nums = (int *)malloc(length * sizeof(int));

    int count;
    for (count = 0; count < length; count++)
        scanf("%d", nums + count);

    printf("%lld\n", sum(nums, length));
}

long long sum(int *a, int n)
{
    long long ans = 0;

    int count;
    for (count = 0; count < n; count++)
        ans += a[count];

    return ans;
}