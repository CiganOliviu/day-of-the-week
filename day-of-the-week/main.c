#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int FindTheNumberOfTheDay(int Day, int Month, int Year)
{
    int Values[12] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

    if (Month < 3)
        Year -= 1;

    return ((Year + Year / 4 - Year / 100 + Year / 400 + Values[Month - 1] + Day) % 7);
}

char * FindTheDayOfTheWeek(int NumberOfTheDay)
{
    char NameOfTheDays[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday","Friday","Saturday"};
    char * DayOfTheWeek = (char *)malloc(10 * sizeof(char));

    for (int i = 0; i < 7; ++i)
        if (NumberOfTheDay == i)
            strcpy(DayOfTheWeek, NameOfTheDays[i]);

    return DayOfTheWeek;
}

int main()
{
    int Day, Month, Year;

    printf("Enter the date : ");
    scanf("%d:%d:%d", &Day, &Month, &Year);

    int NumberOfTheDay = FindTheNumberOfTheDay(Day, Month, Year);

    char DayOfTheWeek[10];
    strcpy(DayOfTheWeek, FindTheDayOfTheWeek(NumberOfTheDay));

    printf("Day %d:%d:%d is a %s.", Day, Month, Year, DayOfTheWeek);

    return 0;
}
