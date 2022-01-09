#include <stdio.h>

void moveTop(int num, int start, int end, int rem);

int main(void)
{
    int num;
    scanf("%d", &num);

    printf("%d\n", (1 << num) - 1);
    moveTop(num, 1, 3, 2);
}

void moveTop(int num, int start, int end, int rem)
{
    if (num == 0)
        return;
    moveTop(num - 1, start, rem, end);
    printf("%d %d\n", start, end);
    moveTop(num - 1, rem, end, start);
}