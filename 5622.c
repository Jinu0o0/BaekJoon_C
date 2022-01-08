#include <stdio.h>

int decode(char letter);

int main(void)
{
    int sum = 0;

    char str[16];
    scanf("%s", str);

    int count;
    for (count = 0; str[count] != '\0'; count++)
        sum += decode(str[count]);

    printf("%d\n", sum);
}

int decode(char letter)
{
    switch (letter)
    {
    case 'A':
    case 'B':
    case 'C':
        return 3;
    case 'D':
    case 'E':
    case 'F':
        return 4;
    case 'G':
    case 'H':
    case 'I':
        return 5;
    case 'J':
    case 'K':
    case 'L':
        return 6;
    case 'M':
    case 'N':
    case 'O':
        return 7;
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
        return 8;
    case 'T':
    case 'U':
    case 'V':
        return 9;
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
        return 10;
    default:
        return 0;
    }
}