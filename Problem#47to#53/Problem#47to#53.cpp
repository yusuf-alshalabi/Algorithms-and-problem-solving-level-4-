
/*
Questione (47 to 53) :

Write a program to read a date and make functions as follows:
-Overload the DayOfWeekOrder to take date structure.
-IsEndOfWeek.
-IsWeekEnd.
-IsBusinessDay.
-DaysUntilTheEndOfWeek.
-DaysUntilTheEndOfMonth.
-DaysUntilTheEndOfYear.

*/

#include <iostream>
#include <iomanip>
#include <ctime>


using namespace std;

struct strDate {
	short year;
	short month;
	short day;
};

bool isLeapYear(short year) {
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}
short getDaysInMonth(short year, short month) {

	if (month < 1 || month>12)
		return 0;

	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return(month == 2) ? (isLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}
int getNumberOfDaysInAYear(short year) {
	return  isLeapYear(year) ? 366 : 365;
}
short getTotalDaysFromBeginningOfTheYear(const strDate& date) {
	short totalDays = date.day;
	for (int i = 1; i < date.month; i++) {
		totalDays += getDaysInMonth(date.year, i);
	}
	return totalDays;
}
bool isLastDayInMonth(const strDate& date) {
	return (date.day == getDaysInMonth(date.year, date.month));
}
bool isLastMonthInYear(short month) {
	return (month == 12);
}

short getDayOfWeekOrder(const strDate& date) {
	short a = (14 - date.month) / 12;
	short y = date.year - a;
	short m = date.month + (12 * a) - 2;
	return(date.day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}
string getDayNameInDate(short DayOfWeekOrder) {
	string nameDays[7] = { "Sunday", "Monday","Tuesday","Wednesday","Thursday", "Friday","Saturday" };

	return nameDays[DayOfWeekOrder];

}

strDate increaseDateByOneDay(strDate date) {
	if (isLastDayInMonth(date)) {
		if (isLastMonthInYear(date.month)) {
			date.year++;
			date.month = 1;
			date.day = 1;
		}
		else {
			date.month++;
			date.day = 1;
		}
	}
	else {
		date.day++;
	}
	return date;
}


bool isEndOfWeek(short dayOrderInWeek) {
	return (dayOrderInWeek == 6);

}
bool isWeekend(short dayOrderInWeek) {
	return (dayOrderInWeek == 5 || dayOrderInWeek == 6);

}
bool isBusinessDay(short dayOrderInWeek) {
	return (!isWeekend(dayOrderInWeek));
}


short getDaysUntilEndOfWeek(strDate date) {
	return (6 - getDayOfWeekOrder(date));
}
short getDaysUntilEndOfMonth(strDate date) {
	return getDaysInMonth(date.year, date.month) - date.day + 1;
}
short getDaysUntilEndOfYear(strDate date) {
	return(getNumberOfDaysInAYear(date.year) - getTotalDaysFromBeginningOfTheYear(date) + 1);
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
		if (!cin.fail() && number >= 1 && number <= getDaysInMonth(year, month)) break;
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

strDate getTodayDate() {
	time_t t = time(0);
	tm now{};

#ifdef _WIN32
	localtime_s(&now, &t);   // Windows
#else
	localtime_r(&t, &now);   // Linux / POSIX
#endif

	return strDate{ short(now.tm_year + 1900), short(now.tm_mon + 1), short(now.tm_mday) };
}

int main()
{
	strDate date = getTodayDate();
	short dayOrderInWeek = getDayOfWeekOrder(date);
	cout << "\nToday is " << getDayNameInDate(dayOrderInWeek) << " , ";
	printDate(date);
	cout << ".\n";
	//------------------------------------------------
	cout << "\nIs it end of week? \n";
	if (isEndOfWeek(dayOrderInWeek)) {
		cout << "Yes ,it is end of week.\n";
	}
	else {
		cout << "No ,it is not end of week.\n";

	}
	//------------------------------------------------
	cout << "\nIs it weekend? \n";
	if (isWeekend(dayOrderInWeek)) {
		cout << "Yes ,it is a weekend.\n";
	}
	else {
		cout << "No ,it is not a weekend.\n";
	}
	//------------------------------------------------
	cout << "\nIs it Business day?\n";
	if (isBusinessDay(dayOrderInWeek)) {
		cout << "Yes ,it is a business day.\n";
	}
	else {
		cout << "No ,it is not a business day.\n";
	}
	//------------------------------------------------
	cout << "\n";
	cout << "Days until end of week : " << getDaysUntilEndOfWeek(date) << " Day(s).\n";
	cout << "Days until end of month : " << getDaysUntilEndOfMonth(date) << " Day(s).\n";
	cout << "Days until end of year : " << getDaysUntilEndOfYear(date) << " Day(s).\n";


	system("pause>0");
	return 0;
}
