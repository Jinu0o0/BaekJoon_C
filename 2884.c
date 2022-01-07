#include <stdio.h>

void setAlarm(int hour, int minute);

int main(void)
{
    int hour, minute;
    scanf("%d %d", &hour, &minute);

    setAlarm(hour, minute);
}

void setAlarm(int hour, int minute)
{
    if (minute >= 45)
        minute -= 45;
    else
    {
        minute += 15;
        if (hour == 0)
            hour = 23;
        else
            hour--;
    }

    printf("%d %d\n", hour, minute);
}