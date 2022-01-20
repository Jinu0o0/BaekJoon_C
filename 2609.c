#include <stdio.h>

int GCM(int num1, int num2);
int LCM(int num1, int num2);

int main(void)
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    printf("%d\n", GCM(num1, num2));
    printf("%d\n", LCM(num1, num2));
}

int GCM(int num1, int num2)
{
    if (num2 > num1)
    {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    if (num1 % num2 == 0)
        return num2;

    GCM(num1 % num2, num2);
}

int LCM(int num1, int num2)
{
    int count;
    for (count = 1;; count++)
    {
        if (count * num1 % num2 == 0)
            return count * num1;
    }
}