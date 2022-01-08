#include <stdio.h>
#include <ctype.h>

#define false 0
#define true 1

int main(void)
{
    int word = 0;

    char str[1000001];
    scanf("%[^\n]s", str);

    int count, inWord = false;
    for (count = 0; str[count] != '\0'; count++)
    {
        if (isspace(str[count]))
        {
            inWord = false;
        }
        else
        {
            if (!inWord)
                word++;
            inWord = true;
        }
    }

    printf("%d\n", word);
}