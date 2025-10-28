
/*

Question (10) :
Write a program to read:
-Day.
-Month.
-Year.
And print total days from the beginning of year.

*/

#include <iostream>

using namespace std;


bool isLeapYear(short year) {
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}
short getDaysInMonth(short year, short month) {

	if (month < 1 || month>12)
		return 0;

	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return(month == 2) ? (isLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}
short getTotalDaysFromBeginningOfTheYear(short year, short month, short day) {
	short totalDays = day;
	for (int i = 1; i < month; i++) {
		totalDays += getDaysInMonth(year, i);
	}
	return totalDays;
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
	cout << "\nNumber of Days from the begining of the year is " << getTotalDaysFromBeginningOfTheYear(year, month, day) << endl;



	system("pause>0");
	return 0;
}
