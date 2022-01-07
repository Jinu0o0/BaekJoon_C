#include <stdio.h>

void add(void);

int main(void)
{
    int test;
    scanf("%d", &test);

    int count;
    for (count = 1; count <= test; count++)
    {
        printf("Case #%d: ", count);
        add();
    }
}

void add(void)
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    printf("%d + %d = %d\n", num1, num2, num1 + num2);
}