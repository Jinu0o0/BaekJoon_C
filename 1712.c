#include <stdio.h>

int roundDown(double num);
void printBreakEvenPoint(int fix, int make, int sell);

int main(void)
{
    int fix_cost, make_cost, sell_cost;
    scanf("%d %d %d", &fix_cost, &make_cost, &sell_cost);

    printBreakEvenPoint(fix_cost, make_cost, sell_cost);
}

void printBreakEvenPoint(int fix, int make, int sell)
{
    if (make >= sell)
    {
        printf("-1\n");
        return;
    }

    int num = roundDown((double)fix / (sell - make));
    printf("%d\n", num + 1);
}

int roundDown(double num)
{
    return (int)num;
}
