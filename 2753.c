#include <stdio.h>

#define false 0
#define true 1

void printLeapYear(int year);

int main(void)
{
    int year;
    scanf("%d", &year);

    printLeapYear(year);
}

void printLeapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                printf("%d\n", true);
            else
                printf("%d\n", false);
        }
        else
            printf("%d\n", true);
    }
    else
        printf("%d\n", false);
}