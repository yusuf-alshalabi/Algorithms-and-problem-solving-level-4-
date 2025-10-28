
/*

Question (7) :
Write a program to read :
-Year.
-Month.
-Day.
And print the day name of week.

*/

#include <iostream>

using namespace std;


bool isLeapYear(short year) {
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}
short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;

	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return(Month == 2) ? (isLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}
short getNumberOfDaysInAYear(short year) {
	return  isLeapYear(year) ? 366 : 365;
}
short getDayOrderInDate(short year, short month, short day) {
	short numDays[7] = { 1,2,3,4,5,6,0 };


	int Days = day - 1;
	for (int i = month - 1; i >= 1; i--) {
		Days = Days + NumberOfDaysInMonth(i, year);
	}

	for (int i = year - 1; i >= 1; i--) {
		Days = Days + getNumberOfDaysInAYear(i);

	}
	return numDays[Days % 7];

}
string getDayNameInDate(short year, short month, short day) {
	string nameDays[7] = { "Sunday", "Monday","Tuesday","Wednesday","Thursday", "Friday","Saturday" };

	return nameDays[getDayOrderInDate(year, month, day)];
}

short getDayOrderInDate(short year, short month, short day) {
	short a = (14 - month) / 12;
	short y = year - a;
	short m = month + (12 * a) - 2;
	return(day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

string getDayNameInDate(short DayOfWeekOrder) {
	string nameDays[7] = { "Sunday", "Monday","Tuesday","Wednesday","Thursday", "Friday","Saturday" };

	return nameDays[DayOfWeekOrder];

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

	if (cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Please enter a number.\n";
		return readMonth();
	}

	return number;
}
short readDay() {
	short number;
	cout << "Enter the day : ";
	cin >> number;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Please enter a number.\n";
		return readDay();
	}

	return number;
}

int main()
{
	short year = readYear();
	short month = readMonth();
	short day = readDay();
	cout << "\n\n";

	//cout << "Date : " << day << "/" << month << "/" << year << ".\n";
	//cout << "Day Order : " << getDayOrderInDate(year, month, day) << ".\n";
	//cout << "Day Name : " << getDayNameInDate(year, month, day) << ".\n";
	//cout << "\n\n";

	cout << "Date : " << day << "/" << month << "/" << year << ".\n";
	cout << "Day Order : " << getDayOrderInDate(year, month, day) << ".\n";
	cout << "Day Name : " << getDayNameInDate(getDayOrderInDate(year, month, day)) << ".\n";



	system("pause>0");
	return 0;
}
