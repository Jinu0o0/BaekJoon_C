#include <stdio.h>
#include <stdlib.h>

void permutationInc(int num, int select);
void printSelectInc(int start, int end, int select, int *selects, int length);

int main(void)
{
    int num, select;
    scanf("%d %d", &num, &select);

    permutationInc(num, select);
}

void permutationInc(int num, int select)
{
    int *selects = (int *)malloc(select * sizeof(int));
    printSelectInc(1, num, select, selects, select);
    free(selects);
}

void printSelectInc(int start, int end, int select, int *selects, int length)
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
        if (end - start + 1 < select)
            return;
        for (count = start; count <= end; count++)
        {
            selects[length - select] = count;
            printSelectInc(count + 1, end, select - 1, selects, length);
        }
    }
}