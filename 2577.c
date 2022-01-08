#include <stdio.h>

void checkNumber(int num);

int main(void)
{
    int num1, num2, num3;
    scanf("%d %d %d", &num1, &num2, &num3);

    checkNumber(num1 * num2 * num3);
}

void checkNumber(int num)
{
    int numbers[10] = {
        0,
    };

    while (num)
    {
        numbers[num % 10]++;
        num /= 10;
    }

    int count;
    for (count = 0; count < 10; count++)
        printf("%d\n", numbers[count]);
}