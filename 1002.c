#include <stdio.h>
#include <math.h>

void turret(void);

int main(void)
{
    int test;
    scanf("%d", &test);

    int count;
    for (count = 0; count < test; count++)
        turret();
}

void turret(void)
{
    double x1, x2;
    double y1, y2;
    double r1, r2;
    scanf("%lf %lf %lf", &x1, &y1, &r1);
    scanf("%lf %lf %lf", &x2, &y2, &r2);

    double distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    int sum = r1 + r2;
    double sub = fabs((double)r1 - r2);
    int result;

    if (distance == 0 && r1 == r2)
        result = -1;
    else if (distance > sum || distance < sub)
        result = 0;
    else if (distance == sum || distance == sub)
        result = 1;
    else
        result = 2;

    printf("%d\n", result);
}