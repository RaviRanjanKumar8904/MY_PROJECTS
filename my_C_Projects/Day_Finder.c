#include <stdio.h>

void dayfinder(int d, int m, int y)
{
    // Assinging code for the day
    // int Sun = 0;
    // int Mon = 1;
    // int Tue = 2;
    // int Wed = 3;
    // int Thr = 4;
    // int Fri = 5;
    // int Sat = 6;

    // Assinging code for the month
    // int Jan = 0;
    // int Feb = 3;
    // int Mar = 3;
    // int Apr = 6;
    // int May = 1;
    // int Jun = 4;
    // int Jul = 6;
    // int Aug = 2;
    // int Sep = 5;
    // int Oct = 0;
    // int Nov = 3;
    // int Dec = 5;

    // Calcuating code of year;
    int yearCode;
    int century = y / 100;
    for (int i = 1; i <= 3; i++)
    {
        if (century % 4 == 0)
        {
            yearCode = 6;
        }
        else if (century % 4 == 1)
        {
            yearCode = 4;
        }
        else if (century % 4 == 2)
        {
            yearCode = 2;
        }
        else if (century % 4 == 3)
        {
            yearCode = 0;
        }
    }

    // Extracting last two digit of year.
    int temp = y, rev = 0, modulo = temp;
    for (int i = 1; i <= 2; i++)
    {
        modulo %= 10;
        rev += modulo;
        if (i == 1)
        {

            rev *= 10;
        }

        temp /= 10;
        modulo = temp;
    }

    // again revert the rev
    int rev2 = 0;
    modulo = rev;
    for (int i = 1; i <= 2; i++)
    {
        modulo %= 10;
        rev2 += modulo;
        if (i == 1)
        {
            rev2 *= 10;
        }

        rev /= 10;
        modulo = rev;
    }

    int LastTWoDigitOfYear = rev2;

    // Finding DAY
    int day = LastTWoDigitOfYear + (LastTWoDigitOfYear / 4) + d + yearCode;
    if (m == 1)
    {
        day += 0;
    }
    else if (m == 2)
    {
        day += 3;
    }
    else if (m == 3)
    {
        day += 3;
    }
    else if (m == 4)
    {
        day += 6;
    }
    else if (m == 5)
    {
        day += 1;
    }
    else if (m == 6)
    {
        day += 4;
    }
    else if (m == 7)
    {
        day += 6;
    }
    else if (m == 8)
    {
        day += 2;
    }
    else if (m == 9)
    {
        day += 5;
    }
    else if (m == 10)
    {
        day += 0;
    }
    else if (m == 11)
    {
        day += 3;
    }
    else if (m == 12)
    {
        day += 5;
    }

    // now , its time to print the final day.
    day %= 7;

    if (day == 0)
    {
        printf("The day is Sunday.");
    }
    if (day == 1)
    {
        printf("The day is Monday.");
    }
    if (day == 2)
    {
        printf("The day is Tuesday.");
    }
    if (day == 3)
    {
        printf("The day is Wednesday.");
    }
    if (day == 4)
    {
        printf("The day is Thrusday.");
    }
    if (day == 5)
    {
        printf("The day is Friday.");
    }
    if (day == 6)
    {
        printf("The day is Saturday.");
    }
}

int main()
{
    // This Program helps to find day of any date you entered.
    int date, month, year;

    printf("DATE: ");
    scanf("%d", &date);
    if (date <= 0 || date >= 32)
    {
        printf("Invalid Entry!!\n Date must be between 1 - 31");
        return 0;
    }

    printf("MONTH: ");
    scanf("%d", &month);
    if (month <= 0 || month >= 13)
    {
        printf("Invalid Entry!!\n Month must be between 1 - 12");
        return 0;
    }

    printf("YEAR: ");
    scanf("%d", &year);
    if (year <= 0 || year >= 9999)
    {
        printf("Invalid Entry!!\n Year must be between 1 - 9999");
        return 0;
    }

    dayfinder(date, month, year);
    return 0;
}

//thankyou