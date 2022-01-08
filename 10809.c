#include <stdio.h>

int main(void)
{
    int alphas[26];

    char str[101];
    scanf("%s", str);

    int count;
    for (count = 0; count < 26; count++)
        alphas[count] = -1;

    int index;
    for (count = 0; str[count] != '\0'; count++)
    {
        index = str[count] - 'a';
        if (alphas[index] == -1)
            alphas[index] = count;
    }

    for (count = 0; count < 26; count++)
        printf("%d ", alphas[count]);
    printf("\n");
}