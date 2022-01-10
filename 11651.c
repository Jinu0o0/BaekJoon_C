#include <stdio.h>
#include <stdlib.h>

struct point
{
    int x;
    int y;
};

void merge(struct point *points, struct point *temps, int start, int end);
void mergeSort(struct point *points, struct point *temps, int start, int end);
void sort(struct point *points, int length);

int main(void)
{
    int length;
    scanf("%d", &length);

    struct point *points = (struct point *)malloc(length * sizeof(struct point));

    int count;
    for (count = 0; count < length; count++)
        scanf("%d %d", &points[count].x, &points[count].y);

    sort(points, length);

    for (count = 0; count < length; count++)
        printf("%d %d\n", points[count].x, points[count].y);

    free(points);
}

void sort(struct point *points, int length)
{
    struct point *temps = (struct point *)malloc(length * sizeof(struct point));
    mergeSort(points, temps, 0, length - 1);
    free(temps);
}

void mergeSort(struct point *points, struct point *temps, int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;
    mergeSort(points, temps, start, mid);
    mergeSort(points, temps, mid + 1, end);
    merge(points, temps, start, end);
}

void merge(struct point *points, struct point *temps, int start, int end)
{
    int mid = (start + end) / 2;

    int start1 = start;
    int end1 = mid;
    int start2 = mid + 1;
    int end2 = end;
    int count = start;

    while (start1 <= end1 && start2 <= end2)
        if (points[start1].y < points[start2].y)
            temps[count++] = points[start1++];
        else if (points[start1].y > points[start2].y)
            temps[count++] = points[start2++];
        else
        {
            if (points[start1].x < points[start2].x)
                temps[count++] = points[start1++];
            else
                temps[count++] = points[start2++];
        }

    while (start1 <= end1)
        temps[count++] = points[start1++];

    while (start2 <= end2)
        temps[count++] = points[start2++];

    for (count = start; count <= end; count++)
        points[count] = temps[count];
}