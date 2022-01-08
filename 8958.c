#include <stdio.h>

void oxProblem(void);

int main(void)
{
    int test;
    scanf("%d", &test);

    int count;
    for (count = 0; count < test; count++)
        oxProblem();
}

void oxProblem(void)
{
    int score = 0, check = 0;

    char ox[81];
    scanf("%s", ox);

    int count;
    for (count = 0; ox[count] == 'O' || ox[count] == 'X'; count++)
    {
        if (ox[count] == 'O')
        {
            check++;
            score += check;
        }
        else
        {
            check = 0;
        }
    }

    printf("%d\n", score);
}