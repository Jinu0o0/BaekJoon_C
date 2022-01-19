#include <stdio.h>
#include <stdlib.h>

int **triangles;

void updateCost(int start, int end);

int main(void)
{
    int height;
    scanf("%d", &height);

    int row, col;
    triangles = (int **)malloc(height * sizeof(int *));
    for (row = 0; row < height; row++)
    {
        *(triangles + row) = (int *)malloc((row + 1) * sizeof(int));
        for (col = 0; col <= row; col++)
            scanf("%d", &triangles[row][col]);
    }

    updateCost(0, height);

    int max = 0;
    for (col = 0; col < height; col++)
        if (max < triangles[height - 1][col])
            max = triangles[height - 1][col];

    printf("%d\n", max);

    for (row = 0; row < height; row++)
        free(*(triangles + row));
    free(triangles);
}

void updateCost(int start, int end)
{
    if (start == end)
        return;

    if (start)
    {
        int count;
        for (count = 0; count <= start; count++)
        {
            if (count == 0)
                triangles[start][count] += triangles[start - 1][count];
            else if (count == start)
                triangles[start][count] += triangles[start - 1][count - 1];
            else
            {
                if (triangles[start - 1][count - 1] > triangles[start - 1][count])
                    triangles[start][count] += triangles[start - 1][count - 1];
                else
                    triangles[start][count] += triangles[start - 1][count];
            }
        }
    }

    updateCost(start + 1, end);
}