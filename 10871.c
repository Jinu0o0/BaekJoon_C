#include <stdio.h>

void checkBound(int upperBound);

int main(void)
{
    int test, upperBound;
    scanf("%d %d", &test, &upperBound);

    int count;
    for (count = 0; count < test; count++)
        checkBound(upperBound);
    printf("\n");
}

void checkBound(int upperBound)
{
    int num;
    scanf("%d", &num);

    if (num < upperBound)
        printf("%d ", num);
}