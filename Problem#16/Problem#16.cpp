
/*

Question (16) :
Write a program to read :
-Date.
And make a function to increace a date by one day.

*/

#include <iostream>
#include <iomanip>
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

bool isLastDayInMonth(const strDate& date) {
	return (date.day == getDaysInMonth(date.year, date.month));
}
bool isLastMonthInYear(short month) {
	return (month == 12);
}

strDate increaseDateByOneDay(strDate date) {
	if (isLastDayInMonth(date)) {
		if (isLastMonthInYear(date.month)) {
			date.year++;
			date.month = 1;
			date.day = 1;
		}
		else {
			date.month++;
			date.day = 1;
		}
	}
	else {
		date.day++;
	}
	return date;
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


void printDate(strDate date) {
	cout << setw(2) << setfill('0') << date.day << "/";
	cout << setw(2) << setfill('0') << date.month << "/";
	cout << setw(4) << setfill('0') << date.year << endl;

}


int main()
{
	strDate date = readDate();
	cout << "\nOriginal Date : ";
	printDate(date);

	strDate nextDate = increaseDateByOneDay(date);
	cout << "\nDate after adding one day is : ";
	printDate(nextDate);
	cout << endl;



	system("pause>0");
	return 0;
}
