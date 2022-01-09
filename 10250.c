#include <stdio.h>

void hotel(void);

int main(void)
{
    int test;
    scanf("%d", &test);

    int count;
    for (count = 0; count < test; count++)
        hotel();
}

void hotel(void)
{
    int height, width, num;
    scanf("%d %d %d", &height, &width, &num);

    int w;
    for (w = 1; num > w * height; w++)
    {
    }

    int h = num - (w - 1) * height;

    printf("%d%.2d\n", h, w);
}