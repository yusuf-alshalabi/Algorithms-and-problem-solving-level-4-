
/*

Question (6) :
Write a program to print Number of Days in a certain month.

Note :
on line logic.

*/

#include <iostream>

using namespace std;

bool isLeapYear(short year) {
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}


short NumberOfDaysInMonth(short month, short year)
{
	if (month < 1 || month>12)
		return 0;

	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return(month == 2) ? (isLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
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
	short Month = readMonth();
	cout << "\nNumber of Days    in Month [" << Month << "] is " << NumberOfDaysInMonth(Month, Year);






	system("pause>0");
	return 0;
}
