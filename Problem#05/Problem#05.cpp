

/*

Question (5) :
Write a program to read :
-Month
And print the number of :
-Days.
-Hours.
-Minutes.
-Seconds.
in acertain month

*/

#include <iostream>

using namespace std;

bool isLeapYear(short year) {
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

int getDaysInMonth(short month, short year) {
	if (month < 1 || month>12) return 0;

	if (month == 2) return isLeapYear ? 29 : 28;

	short month31Days[] = { 1,3,5,7,8,10,12 };
	for (short i = 0; i <= 6; i++) {
		if (month31Days[i] == month) return 31;
	}

	return 30;
}

short numberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month>12) return 0;

	if (Month == 2 && isLeapYear(Year))
		return 29;

	short arrMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return arrMonth[Month - 1];
}

int getNumberOfHoursInAMonth(short month, short year) {
	return getDaysInMonth(month, year) * 24;
}
int getNumberOfMinutesInAMonth(short month, short year) {
	return getNumberOfHoursInAMonth(month, year) * 60;
}
int getNumberOfSecondsInAMonth(short month, short year) {
	return getNumberOfMinutesInAMonth(month, year) * 60;
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

int main()
{
	short Year = readYear();
	short month = readMonth();
	cout << "\nNumber of Days    in Month [" << Year << "] is " << getDaysInMonth(month, Year);
	cout << "\nNumber of Hours   in Month [" << Year << "] is " << getNumberOfHoursInAMonth(month, Year);
	cout << "\nNumber of Minutes in Month [" << Year << "] is " << getNumberOfMinutesInAMonth(month, Year);
	cout << "\nNumber of Seconds in Month [" << Year << "] is " << getNumberOfSecondsInAMonth(month, Year);

	system("pause>0");
	return 0;
}
