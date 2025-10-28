

/*

Question (4) :
Write a program to read :
-Year
And print the number of :
-Days.
-Hours.
-Minutes.
-Seconds.
in acertain year

*/

#include <iostream>

using namespace std;


bool isLeapYear(short year) {
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

int getNumberOfDaysInAYear(short year) {
	return  isLeapYear(year) ? 366 : 365;
}
int getNumberOfHoursInAYear(short year) {
	return getNumberOfDaysInAYear(year) * 24;
}
int getNumberOfMinutesInAYear(short year) {
	return getNumberOfHoursInAYear(year) * 60;
}
int getNumberOfSecondsInAYear(short year) {
	return getNumberOfMinutesInAYear(year) * 60;
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

int main()
{
	short Year = readYear();

	cout << "\nNumber of Days    in Year [" << Year << "] is " << getNumberOfDaysInAYear(Year);
	cout << "\nNumber of Hours   in Year [" << Year << "] is " << getNumberOfHoursInAYear(Year);
	cout << "\nNumber of Minutes in Year [" << Year << "] is " << getNumberOfMinutesInAYear(Year);
	cout << "\nNumber of Seconds in Year [" << Year << "] is " << getNumberOfSecondsInAYear(Year);

	system("pause>0");
	return 0;
}
