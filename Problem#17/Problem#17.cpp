
/*

Question (17) :
Write a program to read :
-Date1.
-Date2.
And make a function to calculate the difference in days.

Note : Date1 should be less than Date2.

*/

#include <iostream>

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


int main()
{
	cout << "Enter Date(1) : \n";
	strDate date1 = readDate();
	cout << "Enter Date(2) : \n";
	strDate date2 = readDate();

	while (!isDate1BeforDate2(date1, date2)) {
		cout << "The Date(2) must be after Date(1)!\nEnter Date(2) Again : \n";
		date2 = readDate();
	}

	cout << "The Number of Days from Date(1) to Date(2) is : "
		<< getDifferenceInDays(date1, date2) << " Day(s)\n";



	cout << "The Number of Days from Date(1) to Date(2) (Including End day) is : "
		<< getDifferenceInDays(date1, date2, true) << " Day(s)\n";


	system("pause>0");
	return 0;
}
