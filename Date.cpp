#pragma once
#include <iostream>
#include "Date.h"
#include <string>

const int Date::days[] = { 0, 31, 28, 31, 30, 31, 30,
31, 31, 30, 31, 30, 31 };

const string Date::monthName[] = { "", "January",
"February", "March", "April", "May", "June",
"July", "August", "September", "October",
"November", "December" };


//function datatype CLASS::f(x)name(arguments)

Date::Date(int m, int d, int y) { setDate(m, d, y); }

bool Date::operator< (Date other) const //you need to implement this
{
	/*int notDue = 0;*/
	if (year < other.getYear())
	{ 
		/*int notDue = 0;*/
		return true;
	}
	else if (year == other.getYear() && month < other.getMonth())
	{
		return true;
	}
	else if (year == other.getYear() && month == other.getMonth() && day < other.getDay()){
		/*int notDue = 0;*/
		return true;
	}
	else
	{
		return false;
	}

	//if (day == other.getDay() || day < other.getDay()){
	//	/*int notDue = 0;*/
	//}
	//else
	//{
	//	return true;
	//}

	//if (notDue == 3)
	//{
	//	return false;
	//}
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

string Date::getMonthString() const
{
	return monthName[month];
}
// Set the date
void Date::setDate(int mm, int dd, int yy)
{
	month = (mm >= 1 && mm <= 12) ? mm : 1;
	year = (yy >= 1900 && yy <= 2100) ? yy : 1900;

	// test for a leap year
	if (month == 2 && leapYear(year))
		day = (dd >= 1 && dd <= 29) ? dd : 1;
	else
		day = (dd >= 1 && dd <= days[month]) ? dd : 1;
}

// Add a specific number of days to a date
// Function call a void function
const Date &Date::operator+=(int additionalDays)
{
	for (int i = 0; i < additionalDays; i++)
		helpIncrement();

	return *this;    // enables cascading
}

// If the year is a leap year, return true; 
// otherwise, return false 
// Change so it test the data member year, not a given testYear
bool Date::leapYear(int year) const
{
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		return true;   // a leap year
	else
		return false;  // not a leap year
}


// Determine if the day is the end of the month
// Change so it test the data member day, not a given testDay
bool Date::endOfMonth(int day) const
{
	if (month == 2 && leapYear(year))
		return (day == 29); // last day of Feb. in leap year
	else
		return (day == days[month]);
}

// Function to help increment the date
void Date::helpIncrement()
{
	if (!endOfMonth(day)) {  // date is not at the end of the month
		day++;
	}
	else if (month < 12) {       // date is at the end of the month, but month < 12
		day = 1;
		++month;
	}
	else       // end of month and year: last day of the year
	{
		day = 1;
		month = 1;
		++year;
	}
}

// Overloaded output operator
ostream &operator<<(ostream &output, const Date &d)
{
	output << d.monthName[d.month] << ' '
		<< d.day << ", " << d.year;

	return output;   // enables cascading
}



