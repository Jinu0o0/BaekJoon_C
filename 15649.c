#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

void permutation(int num, int select);
void printSelect(int num, int select, int *selects, int length);
int isSelect(int num, int *selects, int length);

int main(void)
{
    int num, select;
    scanf("%d %d", &num, &select);

    permutation(num, select);
}

void permutation(int num, int select)
{
    int *selects = (int *)malloc(select * sizeof(int));
    printSelect(num, select, selects, select);
    free(selects);
}

void printSelect(int num, int select, int *selects, int length)
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
            if (!isSelect(count, selects, length))
            {
                selects[length - select] = count;
                printSelect(num, select - 1, selects, length);
                selects[length - select] = 0;
            }
        }
    }
}

int isSelect(int num, int *selects, int length)
{
    int count;
    for (count = 0; count < length; count++)
        if (selects[count] == num)
            return true;

    return false;
}