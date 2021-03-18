//date class implementation file

/* Name: Vicente James Caballero Perez
Date: 4/23/2020
Section: 3330
Assignment: Date Class
Due Date: 5/29/2020
About this project:
Assumptions: valid user input

All work below was performed by Vicente James Caballero Perez */

#include"date.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

//default constructor
Date::Date()
{
    month = 01, day = 01, year = 2000, format = 'D';
}

//alternate constructor
Date::Date(int m, int d, int y)
{
    bool valid;

    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (!y || !m || !d || m > 12 || m < 1 || y < 1582 || d < 1)
        valid=false;
    if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
        monthDays[1]=29;
    else
        monthDays[1]=28;
    if (d > monthDays[m - 1])
        valid=false;
    else
        valid=true;

    if (valid)
    {
        month = m;
        day = d;
        year = y;
    }
    else
    {
        month = 01, day = 01, year = 2000;
    }
    format = 'D';
}

//accessors
int Date::GetMonth()
{
    return month;
}
int Date::GetDay()
{
    return day;
}
int Date::GetYear()
{
    return year;
}

//date change functions
void Date::Input()
{
    int m;
    int d;
    int y;

    cout<< "Please enter a date:(MM/DD/YYYY)\n";
    cin >> m;       // read the month
    cin.get();      // eat slash input
    cin >> d;       // read the day
    cin.get();      // eat slash input
    cin >> y;       // read the year

    //initial validation
    bool valid;

    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
        monthDays[1]=29;
    else
        monthDays[1]=28;
    if (!y || !m || !d || m > 12 || m < 1 || y < 1582 || d < 1)
        valid=false;
    else
        valid = d <= monthDays[m - 1];

    //validation loop
    while (!valid)
    {
        cout << "Invalid Date. Try Again.\n";
        cin >> m;
        cin.get();
        cin >> d;
        cin.get();
        cin >> y;

        if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
            monthDays[1]=29;
        else
            monthDays[1]=28;
        if (!y || !m || !d || m > 12 || m < 1 || y < 1582 || d < 1)
            valid=false;
        else
            valid = d <= monthDays[m - 1];
    }

    month = m;
    day = d;
    year = y;
}

bool Date::Set(int m, int d, int y)
{
    bool valid;

    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
        monthDays[1]=29;
    else
        monthDays[1]=28;
    if (!y || !m || !d || m > 12 || m < 1 || y < 1582 || d < 1)
        valid=false;
    else
        valid = d <= monthDays[m - 1];

    if (valid)
    {
        month = m;
        day = d;
        year = y;
        return true;
    }
    else
        return false;

}

void Date::Increment(int numD=1)
{
    day += numD;

    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        monthDays[1]=29;

    while (day > monthDays[month-1])
    {
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
            monthDays[1]=29;
        else
            monthDays[1]=28;

        day = day - monthDays[month-1];
        month++;

        if (month > 12)
        {
            month -= 12;
            year++;
        }
    }

}

//display functions
bool Date::SetFormat(char f)
{
    if (f=='D' || f=='d' || f=='T' || f=='t' || f=='L' || f=='l' || f=='J' || f=='j')
    {
        format = f;
        return true;
    }
    else
        return false;
}

void Date::Show()
{
    if (format == 'T' or format == 't')
    {
        int newYear = (year%1000)%100;
        cout << setw(2) << setfill('0');
        cout << month << "/" << setw(2) << setfill('0') << day << "/" << setw(2) << setfill('0') << newYear << endl;
    }
    else if (format == 'L' or format == 'l')
    {
        string monthName[] = { "Jan", "Feb", "Mar",
                               "Apr", "May", "June", "July",
                               "Aug", "Sep", "Oct",
                               "Nov", "Dec" };
        cout << monthName[month - 1] << " " << day << " " << year << endl;
    }
    else if (format == 'J' or format == 'j')
    {
        int julianDate;

        //calculation and storage of number of months with 31 and 30 days.
        int months_with_31_days = (static_cast<float>(month)-1)/2 +.5;
        int months_with_30_days;
        if (month%2 == 0)
            months_with_30_days = months_with_31_days - 2;
        else
            months_with_30_days = months_with_31_days -1;
        //ensure non-negative value of months with 30 days
        if (months_with_30_days < 0)
            months_with_30_days = 0;

        if (month==1)
            cout << "The Julian date is " << day << ", " << year << endl;
        if (month==2)
        {
            julianDate  = 31 + day;
            cout << "The Julian date is " << julianDate << ", " << year << endl;
        }
        else
        {
            if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) // it is a leap year
            {
                julianDate = months_with_30_days*30 + months_with_31_days*31 + 29 + day;
                cout << "The Julian date is " << julianDate << ", " << year << endl;
            }
            else
            {
                julianDate = months_with_30_days*30 + months_with_31_days*31 + 28 + day;
                cout << "The Julian date is " << julianDate << ", " << year << endl;
            }
        }
    }
    else
        cout << month << "/" << day << "/" << year << endl;

}

//comparing function
int Date::Compare(const Date& d)
{
    if (d.year < year)
        return 1;
    if (d.year > year)
        return -1;
    if (d.year == year)
    {
        if (d.month < month)
            return 1;
        if (d.month > month)
            return -1;
        if (d.month == month)
        {
            if (d.day < day)
                return 1;
            if (d.day > day)
                return -1;
            if (d.day == day)
                return 0;
        }
    }
}

