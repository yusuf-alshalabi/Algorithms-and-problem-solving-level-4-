
/*

Question (15) :
Write a program to read:
-Date.
And check :
-If it is last Day in Month.
-If it is last Month in Year.

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

bool isLastDayInMonth(strDate date) {
	return (date.day == getDaysInMonth(date.year, date.month));
}

bool isLastMonthInYear(short month) {
	return (month == 12);
}

short readYear() {
	short number;
	while (true) {
		cout << "Enter the year : ";
		cin >> number;
		if (!cin.fail() && number > 0) break;
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Please enter a number.\n";
	}
	return number;
}
short readMonth() {
	short number;
	while (true) {
		cout << "Enter the month : ";
		cin >> number;
		if (!cin.fail() && number >= 1 && number <= 12) break;
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Please enter a number between 1 and 12.\n";
	}
	return number;
}
short readDay(short year, short month) {
	short number;
	while (true) {
		cout << "Enter the day : ";
		cin >> number;
		if (!cin.fail() && number >= 1 && number <= getDaysInMonth(year, month)) break;
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Please enter a valid day for the given month.\n";
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
	strDate date1 = readDate();

	if (isLastDayInMonth(date1)) {
		cout << "\nYes, Day is Last Day in Month.\n";
	}
	else {
		cout << "\nNo, Day is Not Last Day in Month.\n";

	}
	if (isLastMonthInYear(date1.month)) {
		cout << "\nYes, Month is Last Month in Year.";
	}
	else {
		cout << "\nNo, Month is Not Last Month in Year.";

	}


	system("pause>0");
	return 0;
}
