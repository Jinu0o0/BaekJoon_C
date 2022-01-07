#include <stdio.h>

void mulTable(int num);

int main(void)
{
    int num;
    scanf("%d", &num);

    mulTable(num);
}

void mulTable(int num)
{
    int count;
    for (count = 1; count < 10; count++)
        printf("%d * %d = %d\n", num, count, num * count);
}