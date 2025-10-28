
/*

Questione (57) :
Write a program to read Date1 & Date2 ,
And write a function to compares dates,
it should return :
- -1 Befor.
-  0 Equal.
-  1 After.

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

enum enDateCompare { Befor = -1, equal = 0, after = 1 };

enDateCompare compareDates(strDate date1, strDate date2) {
	if (isDate1BeforeDate2(date1, date2))
		return enDateCompare::Befor;

	if (isDate1EqualDate2(date1, date2))
		return enDateCompare::equal;

	//if (isDate1AfterDate2(date1, date2))
	//    return enDateCompare::after;

	return enDateCompare::after;

}

int main()
{
	cout << "Enter Date (1) : \n";
	strDate date1 = readDate();
	cout << "Enter Date (2) : \n";
	strDate date2 = readDate();

	cout << "Compare the date1 & date2 = " << compareDates(date1, date2) << endl;
	cout << "\nNote : \n";
	cout << "-1 = Befor\n";
	cout << " 0 = equal\n";
	cout << " 1 = after\n";








	system("pause>0");
	return 0;
}
