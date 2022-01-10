#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string
{
    int len;
    char *str;
};

void merge(struct string *strings, struct string *temps, int start, int end);
void mergeSort(struct string *strings, struct string *temps, int start, int end);
void sort(struct string *strings, int length);

int main(void)
{
    int length;
    scanf("%d", &length);

    struct string *strings = (struct string *)malloc(length * sizeof(struct string));

    int count;
    for (count = 0; count < length; count++)
    {
        strings[count].str = (char *)malloc(51);
        scanf("%s", strings[count].str);
        strings[count].len = strlen(strings[count].str);
    }

    sort(strings, length);

    printf("%s\n", strings[0].str);
    for (count = 1; count < length; count++)
        if (strcmp(strings[count - 1].str, strings[count].str))
            printf("%s\n", strings[count].str);

    for (count = 0; count < length; count++)
        free(strings[count].str);
    free(strings);
}

void sort(struct string *strings, int length)
{
    struct string *temps = (struct string *)malloc(length * sizeof(struct string));
    mergeSort(strings, temps, 0, length - 1);
    free(temps);
}

void mergeSort(struct string *strings, struct string *temps, int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;
    mergeSort(strings, temps, start, mid);
    mergeSort(strings, temps, mid + 1, end);
    merge(strings, temps, start, end);
}

void merge(struct string *strings, struct string *temps, int start, int end)
{
    int mid = (start + end) / 2;

    int start1 = start;
    int end1 = mid;
    int start2 = mid + 1;
    int end2 = end;
    int count = start;

    while (start1 <= end1 && start2 <= end2)
        if (strings[start1].len < strings[start2].len)
            temps[count++] = strings[start1++];
        else if (strings[start1].len > strings[start2].len)
            temps[count++] = strings[start2++];
        else
        {
            if (strcmp(strings[start1].str, strings[start2].str) < 0)
                temps[count++] = strings[start1++];
            else
                temps[count++] = strings[start2++];
        }

    while (start1 <= end1)
        temps[count++] = strings[start1++];

    while (start2 <= end2)
        temps[count++] = strings[start2++];

    for (count = start; count <= end; count++)
        strings[count] = temps[count];
}