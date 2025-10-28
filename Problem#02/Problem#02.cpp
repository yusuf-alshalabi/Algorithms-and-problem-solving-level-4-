

/*

Question (2) :
Write a program to check if year is a leap year or not.

Note :
All years which are perfectly divisible by 4 are leap years
except for century years (years ending with 00),which are
leap years only if they are perfectly divisible by 400.

*/

#include <iostream>

using namespace std;

bool isLeapYear(short Year) {
	if (Year % 400 == 0) {
		return true;
	}
	else if (Year % 100 == 0) {
		return false;
	}
	else if (Year % 4 == 0) {
		return true;
	}
	else {
		return false;
	}
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
	short year = readYear();
	if (isLeapYear(year)) {
		cout << "Leap Year\n";
	}
	else {
		cout << "Not Leap Year\n";
	}

	system("pause>0");
	return 0;
}
