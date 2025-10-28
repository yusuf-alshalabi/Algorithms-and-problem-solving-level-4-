
/*

Questione (60) :
Write a program to read a period and date,
Then check if date is within this period
or not?

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
void  SwapDates(strDate& Date1, strDate& Date2) {
	strDate TempDate;

	TempDate.year = Date1.year;
	TempDate.month = Date1.month;
	TempDate.day = Date1.day;

	Date1.year = Date2.year;
	Date1.month = Date2.month;
	Date1.day = Date2.day;

	Date2.year = TempDate.year;
	Date2.month = TempDate.month;
	Date2.day = TempDate.day;
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
bool isDate1BetweenDate2AndDate3_Inclusive(strDate date1, strDate date2, strDate date3) {
	return (compareDates(date1, date2) != enDateCompare::Befor && compareDates(date1, date3) != enDateCompare::after);
}

struct strPeriod {
	strDate startDate;
	strDate endDate;
};
strPeriod readPeriod() {
	strPeriod period;
	cout << "Enter Start Date:\n";
	period.startDate = readDate();
	cout << "Enter End Date:\n";
	period.endDate = readDate();

	if (isDate1BeforeDate2(period.endDate, period.startDate)) {
		SwapDates(period.endDate, period.startDate);
	}

	return period;
}

bool isDateInPeriod(strDate date, strPeriod period) {
	return isDate1BetweenDate2AndDate3_Inclusive(date, period.startDate, period.endDate);
}


int main()
{
	cout << "Enter Period : \n";
	strPeriod period = readPeriod();
	cout << "Enter Date to check : \n";
	strDate date = readDate();

	if (isDateInPeriod(date, period)) {
		cout << "Yes, Date is within period.\n";
	}
	else {
		cout << "No, Date is not within period.\n";
	}

	system("pause>0");
	return 0;
}
