#include <stdio.h>

void printBackSeqNum(int num);

int main(void)
{
    int num;
    scanf("%d", &num);

    printBackSeqNum(num);
}

void printBackSeqNum(int num)
{
    int count;
    for (num; num > 0; num--)
        printf("%d\n", num);
}