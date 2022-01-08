#include <stdio.h>

int main(void)
{
    int alphas[26];

    char str[1000001];
    scanf("%s", str);

    int count;
    for (count = 0; str[count] != '\0'; count++)
    {
        if ('a' <= str[count] && str[count] <= 'z')
            alphas[str[count] - 'a']++;
        else
            alphas[str[count] - 'A']++;
    }

    int max = 0, alpha = 0, check = 0;
    for (count = 0; count < 26; count++)
    {
        if (max < alphas[count])
        {
            max = alphas[count];
            alpha = count;
            check = 1;
        }
        else if (max == alphas[count])
        {
            check++;
        }
    }

    if (check != 1)
        printf("?\n");
    else
        printf("%c\n", 'A' + alpha);
}