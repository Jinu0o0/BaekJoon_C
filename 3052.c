#include <stdio.h>

void getRem(int *numbers, int div);
int checkDiff(int *numbers, int length);

int main(void)
{
    int numbers[42] = {
        0,
    };

    getRem(numbers, 42);
    int res = checkDiff(numbers, 42);
    printf("%d\n", res);
}

void getRem(int *numbers, int div)
{
    int number;
    while (scanf("%d", &number) != -1)
        numbers[number % div]++;
}

int checkDiff(int *numbers, int length)
{
    int check = 0;

    int count;
    for (count = 0; count < length; count++)
        if (numbers[count])
            check++;

    return check;
}