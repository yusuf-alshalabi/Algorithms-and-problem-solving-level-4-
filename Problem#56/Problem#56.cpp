
/*

Questione (56) :
Write a program to read Date1 & Date2,
And check if Date1 is after Date2 or not.

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
int getNumberOfDaysInAYear(short year) {
	return  isLeapYear(year) ? 366 : 365;
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

bool isDate1EqualDate2(strDate date1, strDate date2) {
	return  (date1.year == date2.year) ? ((date1.month == date2.month) ? ((date1.day == date2.day) ? true : false) : false) : false;
}
bool isDate1BeforeDate2(strDate date1, strDate date2) {
	return  (date1.year < date2.year) ? true : ((date1.year == date2.year)
		? (date1.month < date2.month ? true : (date1.month == date2.month
			? date1.day < date2.day : false)) : false);
}

bool isDate1AfterDate2(strDate date1, strDate date2) {
	return (!isDate1EqualDate2(date1, date2) && !isDate1BeforeDate2(date1, date2));
}

//bool isDate1AfterDate2(strDate date1, strDate date2) {
//    if (date1.year != date2.year) return date1.year > date2.year;
//    if (date1.month != date2.month) return date1.month > date2.month;
//    return date1.day > date2.day;
//}

int main()
{
	cout << "Enter Date (1) : \n";
	strDate date1 = readDate();
	cout << "Enter Date (2) : \n";
	strDate date2 = readDate();


	if (isDate1AfterDate2(date1, date2)) {
		cout << "\nYes, Date1 is after Date2.\n";
	}
	else {
		cout << "\nNo, Date1 is NOT after Date2.";

	}



	system("pause>0");
	return 0;
}
