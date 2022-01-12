#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

#define INT32_MAX ((1 << 30) - 1) * 2 + 1
#define INT32_MIN 1 << 31

int diffScore(int num, int **spec);
int calDiffScore(int start, int select, int *team, int num, int **spec);
int calDiffScoreHeler(int *team, int num, int **spec);
int abs(int num);

int main(void)
{
    int num;
    scanf("%d", &num);

    int count;
    int **spec = (int **)malloc(num * sizeof(int *));
    for (count = 0; count < num; count++)
        *(spec + count) = (int *)malloc(num * sizeof(int));

    int row, col;
    for (row = 0; row < num; row++)
        for (col = 0; col < num; col++)
            scanf("%d", &spec[row][col]);

    printf("%d\n", diffScore(num, spec));

    for (count = 0; count < num; count++)
        free(*(spec + count));
    free(spec);
}

int diffScore(int num, int **spec)
{
    int *team = (int *)malloc(num * sizeof(int));
    int res = calDiffScore(0, 0, team, num, spec);
    free(team);
    return res;
}

int calDiffScore(int start, int select, int *team, int num, int **spec)
{
    if (select == num / 2)
        return calDiffScoreHeler(team, num, spec);

    if (num / 2 - select > num - start)
        return INT32_MAX;

    int count, min = INT32_MAX, res;
    for (count = start; count < num; count++)
    {
        team[count] = 1;
        res = calDiffScore(count + 1, select + 1, team, num, spec);
        if (min > res)
            min = res;
        team[count] = 0;
    }
    return min;
}

int calDiffScoreHeler(int *team, int num, int **spec)
{
    int person1, person2;
    int score1 = 0, score2 = 0;
    for (person1 = 0; person1 < num - 1; person1++)
        for (person2 = person1 + 1; person2 < num; person2++)
            if (team[person1] && team[person2])
            {
                score1 += spec[person1][person2];
                score1 += spec[person2][person1];
            }
            else if (!team[person1] && !team[person2])
            {
                score2 += spec[person1][person2];
                score2 += spec[person2][person1];
            }

    return abs(score1 - score2);
}

int abs(int num)
{
    if (num < 0)
        return -num;
    else
        return num;
}