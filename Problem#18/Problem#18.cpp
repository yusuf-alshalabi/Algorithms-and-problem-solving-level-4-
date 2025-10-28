
/*

Question (18) :
Write a program that reads:
-Your Date of Birth.
Then calculate your age by days.

*/

#include <iostream>
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
bool isDate1BeforDate2(const strDate& date1, const strDate& date2) {
	return  (date1.year < date2.year) ? true : ((date1.year == date2.year)
		? (date1.month < date2.month ? true : (date1.month == date2.month
			? date1.day < date2.day : false)) : false);
}
int getDifferenceInDays(const strDate& date1, const strDate& date2, bool includeEndDay = false) {
	int days = 0;
	strDate currentDate = date1;
	while (isDate1BeforDate2(currentDate, date2)) {
		currentDate = increaseDateByOneDay(currentDate);
		days++;
	}
	return (includeEndDay ? ++days : days);
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



strDate getSystemDate() {
	strDate Date;
	time_t t = time(0);
	tm localTime;
	localtime_s(&localTime, &t);
	Date.year = localTime.tm_year + 1900;
	Date.month = localTime.tm_mon + 1;
	Date.day = localTime.tm_mday;
	return Date;
}

int main()
{

	strDate date2 = getSystemDate();

	cout << "Enter Your Date of Birth : \n";
	strDate date1 = readDate();

	while (!isDate1BeforDate2(date1, date2)) {
		cout << "Invalid Birth day! This date is not come until now!\nEnter Your Date Of Birth Again : \n";
		date1 = readDate();
	}

	cout << "Your Age is : "
		<< getDifferenceInDays(date1, date2, true) << " Day(s)\n";





	system("pause>0");
	return 0;
}
