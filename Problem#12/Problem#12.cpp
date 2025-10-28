
/*

Question (12) :
Write a program to read :
-Date(year & month & day).
-How many days to add to it.
Print the result date on the screen.

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

strDate getDateFromDayNumber(short dayNumber, short year) {
	strDate date;

	if (dayNumber <= getNumberOfDaysInAYear(year)) {
		date.year = year;
	}
	short month = 1;
	while (dayNumber > 0) {
		short monthDays = getDaysInMonth(year, month);
		if (dayNumber > monthDays) {
			dayNumber -= monthDays;
			month++;
		}
		else {
			date.month = month;
			date.day = dayNumber;
			break;
		}
	}
	return date;
}

strDate addDaysToDate(short days, strDate date) {
	short currentYear = date.year;
	short totalDays = getTotalDaysFromBeginningOfTheYear(date) + days;
	while (totalDays > getNumberOfDaysInAYear(currentYear)) {
		totalDays -= getNumberOfDaysInAYear(currentYear);
		currentYear++;
	}
	return getDateFromDayNumber(totalDays, currentYear);
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


short readHowManyDaysToAdd() {
	short number;
	while (true) {
		cout << "How many days to add ? ";
		cin >> number;
		if (!cin.fail() && number > 0) break;
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Please enter a number.\n";
	}
	return number;
}



void printDate(strDate date) {
	cout << setw(2) << setfill('0') << date.day << "/";
	cout << setw(2) << setfill('0') << date.month << "/";
	cout << setw(4) << setfill('0') << date.year << endl;

}

int main()
{
	strDate date = readDate();
	short addDay = readHowManyDaysToAdd();

	strDate date1 = addDaysToDate(addDay, date);
	printDate(date1);





	system("pause>0");
	return 0;
}
