#include <stdio.h>
#include <stdlib.h>

void permutationDup(int num, int select);
void printSelectDup(int num, int select, int *selects, int length);

int main(void)
{
    int num, select;
    scanf("%d %d", &num, &select);

    permutationDup(num, select);
}

void permutationDup(int num, int select)
{
    int *selects = (int *)malloc(select * sizeof(int));
    printSelectDup(num, select, selects, select);
    free(selects);
}

void printSelectDup(int num, int select, int *selects, int length)
{
    int count;

    if (select == 0)
    {
        for (count = 0; count < length; count++)
            printf("%d ", selects[count]);
        printf("\n");
    }
    else
    {
        for (count = 1; count <= num; count++)
        {
            selects[length - select] = count;
            printSelectDup(num, select - 1, selects, length);
        }
    }
}