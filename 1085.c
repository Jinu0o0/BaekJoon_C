#include <stdio.h>

int main(void)
{
    int x, y, width, height;
    scanf("%d %d %d %d", &x, &y, &width, &height);

    int min = x;
    if (min > y)
        min = y;
    if (min > width - x)
        min = width - x;
    if (min > height - y)
        min = height - y;

    printf("%d\n", min);
}