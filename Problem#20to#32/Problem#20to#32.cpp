
/*

Question (20) to (32) :

Write a program to read
-A date

And make functions to increase date as follows:
-increaseDateByXDays().
-increaseDateByOneWeek().
-increaseDateByXWeeks().
-increaseDateByOneMonth().
-increaseDateByXMonths().
-increaseDateByOneYear().
-increaseDateByXYears().
-increaseDateByXYearsFaster().
-increaseDateByOneDecade().
-increaseDateByXDecades().
-increaseDateByXDecadesFaster().
-increaseDateByOneCentury().
-increaseDateByOneMillennium().

*/
#include <iostream>
#include <iomanip>
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

bool isLastDayInMonth(const strDate& date) {
	return (date.day == getDaysInMonth(date.year, date.month));
}
bool isLastMonthInYear(short month) {
	return (month == 12);
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

strDate increaseDateByXDays(strDate date, int XDays) {
	for (int i = 1; i <= XDays; i++) {
		date = increaseDateByOneDay(date);
	}
	return date;
}

strDate increaseDateByOneWeek(strDate date) {
	for (int i = 1; i <= 7; i++) {
		date = increaseDateByOneDay(date);
	}
	return date;
}

strDate increaseDateByXWeeks(strDate date, int XWeek) {
	for (int i = 1; i <= XWeek; i++) {
		date = increaseDateByOneWeek(date);
	}
	return date;
}

strDate increaseDateByOneMonth(strDate date) {
	if (date.month == 12) {
		date.year++;
		date.month = 1;
	}
	else {
		date.month++;
	}

	short daysInMonth = getDaysInMonth(date.year, date.month);
	if (date.day > daysInMonth) {
		date.day = daysInMonth;
	}

	return date;
}

strDate increaseDateByXMonths(strDate date, int XMonth) {
	int mountOfMonth = date.month + XMonth;
	if (mountOfMonth > 12) {
		date.year += mountOfMonth / 12;
		date.month = mountOfMonth % 12;
	}
	else {
		date.month += XMonth;
	}

	short daysInMonth = getDaysInMonth(date.year, date.month);
	if (date.day > daysInMonth) {
		date.day = daysInMonth;
	}

	return date;
}

strDate increaseDateByOneYear(strDate date) {
	date.year++;

	short daysInMonth = getDaysInMonth(date.year, date.month);
	if (date.day > daysInMonth) {
		date.day = daysInMonth;
	}

	return date;
}


strDate increaseDateByXYears(strDate date, int XYear) {
	for (int i = 1; i <= XYear; i++) {
		date.year++;
	}
	short daysInMonth = getDaysInMonth(date.year, date.month);
	if (date.day > daysInMonth) {
		date.day = daysInMonth;
	}

	return date;

}

strDate increaseDateByXYearsFaster(strDate date, int XYear) {
	date.year += XYear;

	short daysInMonth = getDaysInMonth(date.year, date.month);
	if (date.day > daysInMonth) {
		date.day = daysInMonth;
	}

	return date;
}

strDate increaseDateByOneDecade(strDate date) {
	date.year += 10;

	short daysInMonth = getDaysInMonth(date.year, date.month);
	if (date.day > daysInMonth) {
		date.day = daysInMonth;
	}

	return date;
}

strDate increaseDateByXDecades(strDate date, int XDecades) {
	for (int i = 1; i <= XDecades; i++) {
		date.year += 10;
	}

	short daysInMonth = getDaysInMonth(date.year, date.month);
	if (date.day > daysInMonth) {
		date.day = daysInMonth;
	}

	return date;
}

strDate increaseDateByXDecadesFaster(strDate date, int XDecades) {
	date.year += (XDecades * 10);

	short daysInMonth = getDaysInMonth(date.year, date.month);
	if (date.day > daysInMonth) {
		date.day = daysInMonth;
	}

	return date;
}

strDate increaseDateByOneCentury(strDate date) {
	date.year += 100;

	short daysInMonth = getDaysInMonth(date.year, date.month);
	if (date.day > daysInMonth) {
		date.day = daysInMonth;
	}

	return date;
}

strDate increaseDateByOneMillennium(strDate date) {
	date.year += 1000;

	short daysInMonth = getDaysInMonth(date.year, date.month);
	if (date.day > daysInMonth) {
		date.day = daysInMonth;
	}

	return date;
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


void printDate(strDate date) {
	cout << setw(2) << setfill('0') << date.day << "/";
	cout << setw(2) << setfill('0') << date.month << "/";
	cout << setw(4) << setfill('0') << date.year << endl;

}

void printResult(string messege, strDate date) {
	cout << messege;
	printDate(date);
}


int main()
{
	strDate date = readDate();
	cout << "\nOriginal Date: ";
	printDate(date);

	date = increaseDateByOneDay(date);
	printResult("01-After adding one days: ", date);
	date = increaseDateByXDays(date, 10);
	printResult("02-After adding 10 days: ", date);
	date = increaseDateByOneWeek(date);
	printResult("03-After adding one week: ", date);
	date = increaseDateByXWeeks(date, 3);
	printResult("04-After adding 3 weeks: ", date);
	date = increaseDateByOneMonth(date);
	printResult("05-After adding one month: ", date);
	date = increaseDateByXMonths(date, 5);
	printResult("06-After adding 5 months: ", date);
	date = increaseDateByOneYear(date);
	printResult("07-After adding one year: ", date);
	date = increaseDateByXYears(date, 3);
	printResult("08-After adding 3 years (loop): ", date);
	date = increaseDateByXYearsFaster(date, 3);
	printResult("09-After adding 3 years (fast): ", date);
	date = increaseDateByOneDecade(date);
	printResult("10-After adding one decade: ", date);
	date = increaseDateByXDecades(date, 2);
	printResult("11-After adding 2 decades: ", date);
	date = increaseDateByXDecadesFaster(date, 2);
	printResult("12-After adding 2 decades (fast): ", date);
	date = increaseDateByOneCentury(date);
	printResult("13-After adding one century: ", date);
	date = increaseDateByOneMillennium(date);
	printResult("14-After adding one millennium: ", date);



	system("pause>0");
	return 0;
}
