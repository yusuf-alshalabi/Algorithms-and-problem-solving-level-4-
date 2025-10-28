
/*

Question (9) :
Write a program to read:
-Year.
And print Year Calendar.

*/


#include <iostream>
#include <iomanip>
#include <string>

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
string centerText(const string& text, int width) {
	if (text.length() >= width)
		return text;

	int padding = (width - text.length()) / 2;
	return string(padding, ' ') + text;
}

void printMonthCalendar(short year, short month) {
	short numberOfDaysInMonth = NumberOfDaysInMonth(year, month);
	short firstDayOrder = getDayOrderInDate(year, month, 1);

	printf("\n  _______________%s_______________\n\n",
		monthShortName(month).c_str());

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


void printHeaderForYearCalendar(short year) {
	string title = "Calendar - " + to_string(year);
	const string indent = "  ";
	string line = "_________________________________";

	cout << "\n\n";
	cout << indent << line << endl;
	cout << indent << centerText(title, line.length()) << endl;
	cout << indent << line << endl;
}

void printYearCalendar(short year) {
	printHeaderForYearCalendar(year);
	for (int month = 1; month <= 12; month++) {
		printMonthCalendar(year, month);
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
	printYearCalendar(year);



	system("pause>0");
	return 0;
}
