
/*

Question (8) :
Write a program to read:
-Year.
-Month.
And print month Calendar.

*/

#include <iostream>
#include <iomanip>

using namespace std;


bool isLeapYear(short year) {
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

short NumberOfDaysInMonth(short year, short month)
{
	if (month < 1 || month>12)
		return 0;

	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return(month == 2) ? (isLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}

short getDayOrderInDate(short year, short month, short day) {
	short a = (14 - month) / 12;
	short y = year - a;
	short m = month + (12 * a) - 2;
	return(day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

string monthShortName(short monthNumber) {
	string months[12] = {
	 "Jan"  , "Feb", "Mar"   , "Apr" ,
	 "May"      , "Jun"    , "Jul"    , "Aug",
	 "Sep", "Oct" , "Nov", "Dec"
	};
	return months[monthNumber - 1];
}
string dayShortName(short dayOfWeekOrder) {
	string nameDays[7] = { "Sun", "Mon","Tue","Wed","Thu", "Fri","Sat" };
	return nameDays[dayOfWeekOrder];
}

void printMonthCalendar(short year, short month) {
	short numberOfDaysInMonth = NumberOfDaysInMonth(year, month);
	short firstDayOrder = getDayOrderInDate(year, month, 1);

	printf("\n  ______________ %s ______________\n\n", monthShortName(month).c_str());
	for (int i = 0; i < 7; i++) {
		cout << setw(5) << dayShortName(i);
	}
	cout << endl;
	short day = 1;
	int orderDayInWeek = firstDayOrder;

	for (int i = 0; i < firstDayOrder; i++) {
		cout << setw(5) << " ";
	}

	while (day <= numberOfDaysInMonth) {
		printf("%5d", day);
		day++;

		if (++orderDayInWeek == 7) {
			orderDayInWeek = 0;
			cout << endl;
		}
	}
	cout << endl;
	cout << "  _________________________________\n";
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
	short year = readYear();
	short month = readMonth();
	printMonthCalendar(year, month);





	system("pause>0");
	return 0;
}
