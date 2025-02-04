//
// Created by XX on 2025/2/2.
//

#include <stdio.h>

struct Date {
    int year;
    int month;
    int day;
};

int which_day(struct Date date);

int is_leap_year(int year);

int main()
{
    struct Date date;
    scanf("%d %d %d", &date.year, &date.month, &date.day);
    printf("%d\n", which_day(date));
    return 0;
}

int which_day(struct Date date)
{
    int days = 0;
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap_year(date.year))
    {
        month_days[1] = 29;
    }

    for (int i = 1; i < date.month; i++)
    {
        days += month_days[i - 1];
    }
    days += date.day;

    return days;
}

int is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}