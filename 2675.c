#include <stdio.h>

void strCycle(void);

int main(void)
{
    int test;
    scanf("%d", &test);

    int count;
    for (count = 0; count < test; count++)
        strCycle();
}

void strCycle(void)
{
    int cycle;
    scanf("%d", &cycle);

    char str[21];
    scanf("%s", str);

    int count, rec;
    for (count = 0; str[count] != '\0'; count++)
    {
        for (rec = 0; rec < cycle; rec++)
            printf("%c", str[count]);
    }
    printf("\n");
}