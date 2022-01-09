#include <stdio.h>
#include <stdlib.h>

void getInfo(int *weights, int *heights, int num);
void printRank(int *weights, int *heights, int num, int check);

int main(void)
{
    int num;
    scanf("%d", &num);

    int *weights = (int *)malloc(num * sizeof(num));
    int *heights = (int *)malloc(num * sizeof(num));
    getInfo(weights, heights, num);

    int count;
    for (count = 0; count < num; count++)
        printRank(weights, heights, num, count);
    printf("\n");

    free(weights);
    free(heights);
}

void getInfo(int *weights, int *heights, int num)
{
    int count;
    for (count = 0; count < num; count++)
    {
        scanf("%d", weights + count);
        scanf("%d", heights + count);
    }
}

void printRank(int *weights, int *heights, int num, int check)
{
    int rank = 1;

    int count;
    for (count = 0; count < num; count++)
        if (weights[count] > weights[check] && heights[count] > heights[check])
            rank++;

    printf("%d ", rank);
}