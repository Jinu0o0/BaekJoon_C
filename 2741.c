#include <stdio.h>

void printSeqNum(int num);

int main(void)
{
    int num;
    scanf("%d", &num);

    printSeqNum(num);
}

void printSeqNum(int num)
{
    int count;
    for (count = 1; count <= num; count++)
        printf("%d\n", count);
}