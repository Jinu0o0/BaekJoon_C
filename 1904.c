#include <stdio.h>

int main(void)
{
    int num;
    scanf("%d", &num);

    int num_0, num_1 = 2, num_2 = 1;

    if (num == 1)
        num_0 = num_2;
    else if (num == 2)
        num_0 = num_1;
    else
    {
        int count;
        for (count = 3; count <= num; count++)
        {
            num_0 = (num_1 + num_2) % 15746;
            num_2 = num_1;
            num_1 = num_0;
        }
    }

    printf("%d\n", num_0);
}