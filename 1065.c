#include <stdio.h>

#define false 0
#define true 1

int checkSeqNum(int count);

int main(void)
{
    int check = 0;

    int num;
    scanf("%d", &num);

    int count;
    for (count = 1; count <= num; count++)
        check += checkSeqNum(count);

    printf("%d\n", check);
}

int checkSeqNum(int count)
{
    int diff = count / 10 % 10 - count % 10;

    count /= 10;
    while (count >= 10)
    {
        if (diff != count / 10 % 10 - count % 10)
            return false;
        count /= 10;
    }

    return true;
}