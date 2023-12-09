// According to Gregorian Calendar find day on 1st January of year input year, given 01/01/2001 is on Monday.....

#include <stdio.h>
int main()
{
    int year, days, x, lp = 0;

    printf("INPUT YEAR: ");
    scanf("%u", &year);

    // If input year is after 2001(given)
    if (year >= 2001)
    {
        // Loop to calulate number of leap years between 2001 and input year
        for (x = 2003; x < year; x++)
        {
            if (x % 400 == 0 || (x % 4 == 0 && x % 100 != 0))
                lp++;
        }

        // Difference Between input year and given year
        x = year - 2001;
        // Finding total number of days between both years
        days = (x * 365) + lp;
        // Get remainder to find day on 1 jan
        days = days % 7;
    }

    // If input year is before 2001(given)
    else
    {
        // Loop to calulate number of years between input year and 2001
        for (x = year; x <= 2000; x++)
        {
            if (x % 400 == 0 || (x % 4 == 0 && x % 100 != 0))
                lp++;
        }

        // Difference Between input year and given year
        x = year - 2001;
        // Finding total number of days between both years (but in negative)
        days = (x * 365) - lp;
        // Calculation to find day on 1 jan
        days = (days % 7) + 7;
    }

    printf("1 January was on ");
    switch (days)
    {

    case 0:
        printf("MONDAY");
        break;
    case 1:
        printf("TUESDAY");
        break;
    case 2:
        printf("WEDNESDAY");
        break;
    case 3:
        printf("THURSDAY");
        break;
    case 4:
        printf("FRIDAY");
        break;
    case 5:
        printf("SATURDAY");
        break;
    case 6:
        printf("SUNDAY");
        break;
    }

    return 0;
}
