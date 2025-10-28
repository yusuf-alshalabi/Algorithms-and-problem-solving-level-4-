
/*

Question (11) :
Write a program to read:
-Day.
-Month.
-Year.
And print total days from the beginning of year.
Then : Take the total days and convert them back to date.

*/

#include <iostream>

using namespace std;

struct strDate {
	short year;
	short month;
	short day;
};

bool isLeapYear(short year) {
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}
short getDaysInMonth(short year, short month) {

	if (month < 1 || month>12)
		return 0;

	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return(month == 2) ? (isLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}
int getNumberOfDaysInAYear(short year) {
	return  isLeapYear(year) ? 366 : 365;
}
short getTotalDaysFromBeginningOfTheYear(const strDate& date) {
	short totalDays = date.day;
	for (int i = 1; i < date.month; i++) {
		totalDays += getDaysInMonth(date.year, i);
	}
	return totalDays;
}

strDate getDateFromDayNumber(short dayNumber, short year) {
	strDate date;

	if (dayNumber <= getNumberOfDaysInAYear(year)) {
		date.year = year;
	}
	short month = 1;
	while (dayNumber > 0) {
		short monthDays = getDaysInMonth(year, month);
		if (dayNumber > monthDays) {
			dayNumber -= monthDays;
			month++;
		}
		else {
			date.month = month;
			date.day = dayNumber;
			break;
		}
	}
	return date;
}

short readYear() {
	short number;
	cout << "Enter the year : ";
	cin >> number;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Please enter a number.\n";
		return readYear();
	}

	return number;
}
short readMonth() {
	short number;
	cout << "Enter the month : ";
	cin >> number;

	if (cin.fail() || number < 1 || number>12) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Please enter a number.\n";
		return readMonth();
	}

	return number;
}
short readDay(short year, short month) {
	short number;
	cout << "Enter the day : ";
	cin >> number;

	if (cin.fail() || number > getDaysInMonth(year, month)) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Please enter a number.\n";
		return readDay(year, month);
	}

	return number;
}
strDate readDate() {
	strDate date;
	date.year = readYear();
	date.month = readMonth();
	date.day = readDay(date.year, date.month);
	return date;
}


int main()
{
	strDate date = readDate();
	short dayNumber = getTotalDaysFromBeginningOfTheYear(date);
	cout << "\nNumber of Days from the begining of the year is " << dayNumber << "\n\n\n";



	strDate date1 = getDateFromDayNumber(dayNumber, date.year);

	cout << "Date for [" << dayNumber << "] is: ";
	cout << date1.day << "/" << date1.month << "/" << date1.year << endl;


	system("pause>0");
	return 0;
}
