#include <stdio.h>

int main(void)
{
    int test;
    scanf("%d", &test);

    int count, cute, cuteCount = 0;
    for (count = 0; count < test; count++)
    {
        scanf("%d", &cute);
        if (cute)
            cuteCount++;
    }

    if (cuteCount > test - cuteCount)
        printf("Junhee is cute!\n");
    else
        printf("Junhee is not cute!\n");
}