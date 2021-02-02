#include <stdio.h>

/*
    Problem:
    You are given the following information, but you may prefer to do some research for yourself.

    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century 
    unless it is divisible by 400. How many Sundays fell on the first of the 
    month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

    Solution:
    To solve this problem, we will use the information given to calculate if 
    the 1st of each month is also a sunday.
    If the 1st January 1900 was a monday, then we can use this date as an 
    offset to calculate if other days are a sunday.
    The amount of days passed since 1st jan 1900 modulated by the number of
    days in a week will tell us what day of the week a particular day is.
    Since we are interested in sundays, our number is 6.

*/

int main(int argc, char const *argv[])
{
    int counter = 0;
    long int daysCounted = 0;
    int normYear = 365;
    int leapYear = 366;
    int startYear = 1901;
    int endYear = 2001;

    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(1900 % 4 == 0 && 1900 % 400 == 0)
    {
        daysCounted += leapYear;
    }
    else
    {
        daysCounted += normYear;
    }

    for(int i = startYear; i < endYear; i++)
    {
        if(i % 4 == 0)
        {
            months[1] = 29;
        }
        else
        {
            months[1] = 28;
        }

        for(int j = 0; j < 12; j++)
        {
            if(daysCounted % 7 == 6)
            {
                counter++;
            }
            daysCounted += months[j];
        }
    }

    printf("There are %d sundays that occur on the first of the month\n", counter);    
    return 0;
}
