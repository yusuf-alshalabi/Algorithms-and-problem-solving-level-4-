
/*

Question (33 to 46) :

Write a program to read:
-A date.

And make functions to decrease the date as follows:
-DecreaseDateByOneDay.
-DecreaseDateByXDays.
-DecreaseDateByOneWeek.
-DecreaseDateByXWeeks.
-DecreaseDateByOneMonth.
-DecreaseDateByXMonths.
-DecreaseDateByOneYear.
-DecreaseDateByXYears.
-DecreaseDateByXYearsFaster.
-DecreaseDateByOneDecade.
-DecreaseDateByXDecades.
-DecreaseDateByXDecadesFaste.
-DecreaseDateByOneCentury.
-DecreaseDateByOneMillennium.


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

void fixDayInMonth(strDate& date) {
	short daysInMonth = getDaysInMonth(date.year, date.month);
	if (date.day > daysInMonth) {
		date.day = daysInMonth;
	}
}

strDate decreaseDateByOneDay(strDate date) {
	if (date.day > 1) {
		date.day--;
		return date;
	}

	if (date.month > 1) {
		date.month--;
	}
	else {
		if (date.year == 1) {
			return date;
		}
		date.year--;
		date.month = 12;
	}
	date.day = getDaysInMonth(date.year, date.month);
	return date;
}

strDate decreaseDateByXDays(strDate date, int XDays) {
	for (int i = 1; i <= XDays; i++) {
		date = decreaseDateByOneDay(date);
	}
	return date;
}
strDate decreaseDateByOneWeek(strDate date) {
	date = decreaseDateByXDays(date, 7);
	return date;
}
strDate decreaseDateByXWeeks(strDate date, int XWeek) {
	date = decreaseDateByXDays(date, XWeek * 7);
	return date;
}

strDate decreaseDateByOneMonth(strDate date) {
	if (date.month == 1) {
		if (date.year == 1) return date;
		date.year--;
		date.month = 12;
	}
	else {
		date.month--;
	}

	fixDayInMonth(date);
	return date;

}
strDate decreaseDateByXMonths(strDate date, int XMonths) {
	for (int i = 1; i <= XMonths; i++) {
		date = decreaseDateByOneMonth(date);
	}
	return date;
}

strDate decreaseDateByOneYear(strDate date) {
	if (date.year == 1) {
		return date;
	}
	date.year--;

	fixDayInMonth(date);

	return date;

}
strDate decreaseDateByXYears(strDate date, int XYears) {
	for (int i = 1; i <= XYears; i++) {
		date = decreaseDateByOneYear(date);
	}
	return date;
}
strDate decreaseDateByXYearsFaster(strDate date, int XYears) {
	if (date.year < XYears) {
		return date;
	}
	date.year -= XYears;

	fixDayInMonth(date);

	return date;

}
strDate decreaseDateByOneDecade(strDate date) {
	if (date.year < 10) {
		return date;
	}
	date.year -= 10;

	fixDayInMonth(date);

	return date;
}
strDate decreaseDateByXDecades(strDate date, int XDecades) {
	for (int i = 1; i <= XDecades; i++) {
		date = decreaseDateByOneDecade(date);
	}
	return date;
}
strDate decreaseDateByXDecadesFaster(strDate date, int XDecades) {
	if (date.year < (XDecades * 10)) {
		return date;
	}
	date.year -= (XDecades * 10);

	fixDayInMonth(date);

	return date;
}
strDate decreaseDateByOneCentury(strDate date) {
	if (date.year < 100) {
		return date;
	}
	date.year -= 100;

	fixDayInMonth(date);

	return date;
}
strDate decreaseDateByOneMillennium(strDate date) {
	if (date.year < 1000) {
		return date;
	}
	date.year -= 1000;

	fixDayInMonth(date);

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
	strDate date = readDate();
	cout << "Original Date : \n";
	printDate(date);


	cout << "\nDate After:\n\n";
	date = decreaseDateByOneDay(date);
	printResult("01-Subtracting one day is: ", date);
	date = decreaseDateByXDays(date, 10);
	printResult("02-Subtracting 10 days is: ", date);
	date = decreaseDateByOneWeek(date);
	printResult("03-Subtracting one week is: ", date);
	date = decreaseDateByXWeeks(date, 10);
	printResult("04-Subtracting 10 weeks is: ", date);
	date = decreaseDateByOneMonth(date);
	printResult("05-Subtracting one month is: ", date);
	date = decreaseDateByXMonths(date, 5);
	printResult("06-Subtracting 5 months is: ", date);
	date = decreaseDateByOneYear(date);
	printResult("07-Subtracting one year is: ", date);
	date = decreaseDateByXYears(date, 10);
	printResult("08-Subtracting 10 years is: ", date);
	date = decreaseDateByXYearsFaster(date, 10);
	printResult("09-Subtracting 10 Years (faster) is: ", date);
	date = decreaseDateByOneDecade(date);
	printResult("10-Subtracting one Decade is: ", date);
	date = decreaseDateByXDecades(date, 10);
	printResult("11-Subtracting 10 Decades is: ", date);
	date = decreaseDateByXDecadesFaster(date, 10);
	printResult("12-Subtracting 10 Decade (faster) is: ", date);
	date = decreaseDateByOneCentury(date);
	printResult("13-Subtracting One Century is: ", date);
	date = decreaseDateByOneMillennium(date);
	printResult("14-Subtracting One Millennium is: ", date);
	cout << endl;

	system("pause>0");
	return 0;
}
