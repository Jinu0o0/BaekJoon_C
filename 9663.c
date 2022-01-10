#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

int queen(int num, int *chess, int size);
int check(int num, int *chess, int size);
int abs(int num);

int main(void)
{
    int size;
    scanf("%d", &size);

    int count;
    int *chess = (int *)calloc(size, sizeof(int));

    printf("%d\n", queen(0, chess, size));

    free(chess);
}

int queen(int num, int *chess, int size)
{
    if (num == size)
        return 1;

    int count, res = 0;
    for (count = 0; count < size; count++)
    {
        chess[num] = count;
        if (check(num, chess, size))
            res += queen(num + 1, chess, size);
    }

    return res;
}

int check(int num, int *chess, int size)
{
    int count;
    for (count = 0; count < num; count++)
        if (chess[count] == chess[num])
            return false;
        else if (num - count == abs(chess[num] - chess[count]))
            return false;

    return true;
}

int abs(int num)
{
    if (num < 0)
        return -num;
    else
        return num;
}