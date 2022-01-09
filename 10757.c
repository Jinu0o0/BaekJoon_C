#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int decode(char num);
void addStrSeq(char *num1, char *num2, int length1, int length2, char *res);
void strReverse(char *num, int length);
void printAdd(char *num1, char *num2);

int main(void)
{
    char num1[10002], num2[10002];
    scanf("%s %s", num1, num2);

    printAdd(num1, num2);
}

void printAdd(char *num1, char *num2)
{
    int length1 = strlen(num1);
    int length2 = strlen(num2);

    strReverse(num1, length1);
    strReverse(num2, length2);

    char *res = (char *)malloc(length1 > length2 ? length1 + 1 : length2 + 1);
    addStrSeq(num1, num2, length1, length2, res);
    int lengthRes = strlen(res);
    strReverse(res, lengthRes);

    printf("%s\n", res);
    free(res);
}

void strReverse(char *num, int length)
{
    char *temp = (char *)malloc(length);

    int count;
    for (count = 0; count < length; count++)
        temp[count] = num[length - count - 1];

    for (count = 0; count < length; count++)
        num[count] = temp[count];

    free(temp);
}

void addStrSeq(char *num1, char *num2, int length1, int length2, char *res)
{
    int count, sum = 0, carry = 0;
    for (count = 0; count < length1 || count < length2 || carry; count++)
    {
        sum = 0;
        if (count < length1)
            sum += decode(num1[count]);
        if (count < length2)
            sum += decode(num2[count]);
        sum += carry;
        carry = sum / 10;
        sum %= 10;

        res[count] = sum + '0';
    }

    res[count] = '\0';
}

int decode(char num)
{
    if ('0' <= num && num <= '9')
        return num - '0';
    else
        return 0;
}