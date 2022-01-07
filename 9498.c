#include <stdio.h>

void printScore(int score);

int main(void)
{
    int score;
    scanf("%d", &score);

    printScore(score);
}

void printScore(int score)
{
    switch (score / 10)
    {
    case 10:
    case 9:
        printf("A\n");
        break;
    case 8:
        printf("B\n");
        break;
    case 7:
        printf("C\n");
        break;
    case 6:
        printf("D\n");
        break;
    default:
        printf("F\n");
        break;
    }
}