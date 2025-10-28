
/*

Questione (62) :
Write a program to read Date and write
a function to validate this date.

*/

#include<iostream>
#include<iomanip>

using namespace std;

struct strDate { short year; short month; short day; };


bool isLeapYear(short year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
short numberOfDaysInAMonth(short month, short year) {
	if (month < 1 || month>12) return  0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (isLeapYear(year) ? 29 : 28) : days[month - 1];
}

bool isValidDate(strDate Date) {
	if (Date.month < 1 || Date.month>12) return false;
	if (Date.day < 1) return false;

	short DaysInMonth = numberOfDaysInAMonth(Date.month, Date.year);
	return (Date.day <= DaysInMonth);

}
short ReadDay() {
	short Day;
	cout << "\nPlease enter a Day? ";
	cin >> Day; return Day;
}
short ReadMonth() {
	short Month;
	cout << "Please enter a Month? ";
	cin >> Month;
	return Month;
}
short ReadYear() {
	short Year;
	cout << "Please enter a Year? ";
	cin >> Year; return Year;
}
strDate ReadDate() {
	strDate Date;
	Date.day = ReadDay();
	Date.month = ReadMonth();
	Date.year = ReadYear();
	return Date;
}



void printDate(strDate date) {
	cout << setw(2) << setfill('0') << date.day << "/";
	cout << setw(2) << setfill('0') << date.month << "/";
	cout << setw(4) << setfill('0') << date.year;

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
		if (!cin.fail() && number >= 1 && number <= numberOfDaysInAMonth(year, month)) break;
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

int main() {
	strDate Date1 = ReadDate();
	if (isValidDate(Date1))
		cout << "\nYes, Date is a valide date.\n";
	else
		cout << "\nNo, Date is a NOT valide date\n";

	strDate date2 = readDate();

	system("pause>0");
	return 0;
}