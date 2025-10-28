

/*

Question (3) :
Solve Leap year Problem with one line of code only.

Note :
Use Logical Operators.

*/

#include <iostream>

using namespace std;


bool isLeapYear(short year) {
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
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
