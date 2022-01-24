#include <stdio.h>

int main(void)
{
    int num1, num2;

    while(scanf("%d %d", &num1, &num2) && (num1 || num2))
        if (num1 > num2)
            printf("Yes\n");
        else
            printf("No\n");
}