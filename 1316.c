#include <stdio.h>

#define false 0
#define true 1

int checkGroupWord(void);

int main(void)
{
    int check = 0;

    int test;
    scanf("%d", &test);

    int count;
    for (count = 0; count < test; count++)
        check += checkGroupWord();

    printf("%d\n", check);
}

int checkGroupWord(void)
{
    int alphas[26] = {
        0,
    };

    char str[101];
    scanf("%s", str);

    int count, before = -1, now = -1;
    for (count = 0; str[count] != '\0'; count++)
    {
        now = str[count] - 'a';
        if (before != now)
        {
            if (alphas[now])
                return 0;
            alphas[now]++;
            before = now;
        }
    }

    return true;
}