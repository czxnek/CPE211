// **************************************************************
// **************************************************************
//
// **********  DO NOT MODIFY ANYTHING IN THIS SECTION
//
// solution cpp file for project 11
// all helper function definitions go in this file

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Project_10.h" // gives access to function definitions in the .h file

using namespace std;

// **************************************************************
// **************************************************************
//
// **************************************************************
// **********   PUT ALL FUNCTION DEFINITIONS BELOW THIS COMMENT
//
// Function definitions start here. 

// ************** CONTRUCTORS **************
Date::Date()
{
	month = 1;
	day = 1;
	year = 1900;
}
Date::Date(int initMonth, int initDay, int initYear)
{
	month = initMonth;
	day = initDay;
	year = initYear;

}
Date::Date(int initMonth, int initYear)
{
	month = initMonth;
	year = initYear;
	day = 1;
}

// ************** TRANSFORMERS **************
void Date::SetDate(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
}
void Date::IncrementDate()
{
	// test for when a new  month is moved into and when a new year is moved into because of the increment
	switch (month) // increments and resets days of month according to amount of days in each month
	{

	case 1: day++;

		if (day > 31)
		{
			day = 0;
			day++;
			month++;
		}break;

	case 2: day++;
		if (day > 28)
		{
			day = 0;
			day++;
			month++;
		}break;

	case 3: day++;
		if (day > 31)
		{
			day = 0;
			day++;
			month++;
		}break;

	case 4: day++;

		if (day > 30)
		{
			day = 0;
			day++;
			month++;
		}break;

	case 5: day++;

		if (day > 31)
		{
			day = 0;
			day++;
			month++;
		}break;

	case 6: day++;

		if (day > 30)
		{
			day = 0;
			day++;
			month++;
		}break;

	case 7: day++;

		if (day > 31)
		{
			day = 0;
			day++;
			month++;
		}break;

	case 8: day++;

		if (day > 31)
		{
			day = 0;
			day++;
			month++;
		}break;

	case 9: day++;

		if (day > 30)
		{
			day = 0;
			day++;
			month++;
		}break;

	case 10: day++;

		if (day > 31)
		{
			day = 0;
			day++;
			month++;
		}break;

	case 11: day++;

		if (day > 30)
		{
			day = 0;
			day++;
			month++;
		}break;

	case 12: day++;

		if (day > 31)
		{
			day = 0;
			day++;
			month++;
			year++;
		}break;
	default: month = 0; month++; day = 2;
	}	// end of switch statement

	

	if (year > 9999) // increments year, resets after 9999
	{
		year = 0;
		year++;
	}
}
// ************** OBSERVERS *******************
	// write out date in format of MM/DD/YYYY
void Date::WriteNumberFormat() const 
{

	if (month < 10 || day < 10) // adding zeroes before single digit months and days to match format
	{
		cout << setfill('0');
		cout << right << setw(2) << month << "/";
		cout << right << setw(2) << day << "/";
		cout << right << year << endl;
		cout << setfill(' ');
	}
	else // if they are already double digits, print as usual
	{
		cout << month << "/" << day << "/" << year << endl;
	}

}

// write out date in MONTH DAY, YEAR format
void Date::WriteNameFormat() const
{


	switch (month)
	{
	case JAN: cout <<  "January"<< " " << day << ", " << year << endl;
		break;
	case FEB: cout << "February"<< " " << day << ", " << year << endl;
		break;
	case MAR: cout << "March"<< " " << day << ", " << year << endl;
		break;
	case APR: cout <<  "April"<< " " << day << ", " << year << endl;
		break;
	case MAY: cout <<  "May"<< " " << day << ", " << year << endl;
		break;
	case JUN: cout <<  "June"<< " " << day << ", " << year << endl;
		break;
	case JUL: cout <<  "July"<< " " << day << ", " << year << endl;
		break;
	case AUG: cout <<  "August"<< " " << day << ", " << year << endl;
		break;
	case SEP: cout << "September" << " " << day << ", " << year << endl;
		break;
	case OCT: cout << "October"<< " " << day << ", " << year << endl;
		break;
	case NOV: cout <<  "November"<< " " << day << ", " << year << endl;
		break;
	case DEC: cout << "December"<< " " << day << ", " << year << endl;
		break;
		
	}
	
}

// determine if two dates are the same
bool Date::SameDate(Date otherDate) const
{
	if (day == otherDate.day)
	{
		return true;
	}
	else
		return false;
	if (month == otherDate.month)
	{
		return true;
	}
	else
		return false;
	if (year == otherDate.year)
	{
		return true;
    }
	else
		return false;
}

// determine if one date is before the other date
bool Date::BeforeDate(Date otherDate) const
{
	if (otherDate.day > day) // if the rhs is greater than lhs
	{
		return true;
	}
	
	else if (otherDate.month > month)
	{
		return true;
	}

	else if (otherDate.year > year)
	{
		return true;
	}
	
	else if ((otherDate.day < day || otherDate.day == day) || (otherDate.month < month || otherDate.month == month )|| (otherDate.year < year || otherDate.year == year))
	{
		return false;
	}
	
}

// determine if one date is after the other date
bool Date::AfterDate(Date otherDate) const
{
	if (otherDate.day < day || otherDate.month < month || otherDate.year < year)
		return true;
	else if(otherDate.day > day || otherDate.month > month || otherDate.year > year)
		return false;
	else return false;


}
