#include <stdio.h>
#include <math.h>

int main(void)
{
    int radius;
    scanf("%d", &radius);

    printf("%lf\n", M_PI * radius * radius);
    printf("%lf\n", (double)2 * radius * radius);
}