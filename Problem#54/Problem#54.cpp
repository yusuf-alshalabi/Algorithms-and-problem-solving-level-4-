
/*

Questione (54) :
Write a program to read Vacation Period DateFrom and DateTo
and make a function to calculate the actual vacation days.

Note: Weekends are excluded.

*/

#include <iostream>
#include <iomanip>

using namespace std;


struct strDate {
	short year;
	short month;
	short day;
};

short getDayOfWeekOrder(const strDate& date) {
	short a = (14 - date.month) / 12;
	short y = date.year - a;
	short m = date.month + (12 * a) - 2;
	return(date.day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

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
bool isLastDayInMonth(const strDate& date) {
	return (date.day == getDaysInMonth(date.year, date.month));
}
bool isLastMonthInYear(short month) {
	return (month == 12);
}
bool isWeekend(short dayOrderInWeek) {
	return (dayOrderInWeek == 5 || dayOrderInWeek == 6);

}
bool isBusinessDay(strDate date) {
	return (!isWeekend(getDayOfWeekOrder(date)));
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


string getDayNameInDate(short DayOfWeekOrder) {
	string nameDays[7] = { "Sunday", "Monday","Tuesday","Wednesday","Thursday", "Friday","Saturday" };

	return nameDays[DayOfWeekOrder];

}

bool isDate1BeforOrEqualDate2(strDate d1, strDate d2) {
	if (d1.year != d2.year)
		return d1.year < d2.year;

	if (d1.month != d2.month)
		return d1.month < d2.month;

	return d1.day <= d2.day;
}



short actualVocationDays(strDate vocationFrom, strDate vocationTo) {
	short days = 0;
	if (!isDate1BeforOrEqualDate2(vocationFrom, vocationTo)) {
		return 0;
	}

	while (isDate1BeforOrEqualDate2(vocationFrom, vocationTo)) {
		if (isBusinessDay(vocationFrom))
			days++;

		vocationFrom = increaseDateByOneDay(vocationFrom);
	}

	return days;
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

int main()
{
	cout << "Vocation Start : \n";
	strDate DateFrom = readDate();
	cout << "Vocation End : \n";
	strDate DateTo = readDate();

	cout << "Vocation from : ";
	cout << getDayNameInDate(getDayOfWeekOrder(DateFrom)) << " , ";

	printDate(DateFrom);
	cout << ".\n";

	cout << "Vocation To : ";
	cout << getDayNameInDate(getDayOfWeekOrder(DateTo)) << " , ";
	printDate(DateTo);
	cout << ".\n";

	cout << "Actucal Vocation days is : " << actualVocationDays(DateFrom, DateTo) << ".\n";


	system("pause>0");
	return 0;
}
