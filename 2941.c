#include <stdio.h>

int decode(char *str, int place);

int main(void)
{
    int check = 0;

    char str[101];
    scanf("%s", str);

    int count, jump;
    for (count = 0; str[count] != '\0'; count++)
    {
        jump = decode(str, count);
        check++;
        count += jump;
    }

    printf("%d\n", check);
}

int decode(char *str, int place)
{
    if (str[place + 1] == '\0')
        return 0;
    else
    {
        if (str[place] == 'c' && str[place + 1] == '=')
            return 1;
        if (str[place] == 'c' && str[place + 1] == '-')
            return 1;
        if (str[place] == 'd' && str[place + 1] == '-')
            return 1;
        if (str[place] == 'l' && str[place + 1] == 'j')
            return 1;
        if (str[place] == 'n' && str[place + 1] == 'j')
            return 1;
        if (str[place] == 's' && str[place + 1] == '=')
            return 1;
        if (str[place] == 'z' && str[place + 1] == '=')
            return 1;

        if (str[place + 2] == '\0')
            return 0;
        else
        {
            if (str[place] == 'd' && str[place + 1] == 'z' && str[place + 2] == '=')
                return 2;
        }
    }

    return 0;
}