#include <stdio.h>
#include <stdlib.h>

struct person
{
    int age;
    char name[101];
};

void merge(struct person *people, struct person *temps, int start, int end);
void mergeSort(struct person *people, struct person *temps, int start, int end);
void sort(struct person *people, int length);

int main(void)
{
    int length;
    scanf("%d", &length);

    struct person *people = (struct person *)malloc(length * sizeof(struct person));

    int count;
    for (count = 0; count < length; count++)
        scanf("%d %s", &people[count].age, people[count].name);

    sort(people, length);

    for (count = 0; count < length; count++)
        printf("%d %s\n", people[count].age, people[count].name);

    free(people);
}

void sort(struct person *people, int length)
{
    struct person *temps = (struct person *)malloc(length * sizeof(struct person));
    mergeSort(people, temps, 0, length - 1);
    free(temps);
}

void mergeSort(struct person *people, struct person *temps, int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;
    mergeSort(people, temps, start, mid);
    mergeSort(people, temps, mid + 1, end);
    merge(people, temps, start, end);
}

void merge(struct person *people, struct person *temps, int start, int end)
{
    int mid = (start + end) / 2;

    int start1 = start;
    int end1 = mid;
    int start2 = mid + 1;
    int end2 = end;
    int count = start;

    while (start1 <= end1 && start2 <= end2)
        if (people[start1].age <= people[start2].age)
            temps[count++] = people[start1++];
        else
            temps[count++] = people[start2++];

    while (start1 <= end1)
        temps[count++] = people[start1++];

    while (start2 <= end2)
        temps[count++] = people[start2++];

    for (count = start; count <= end; count++)
        people[count] = temps[count];
}