
/*

Questione (61) :
Write a program to read two periods
Then count overlap days?

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
enum enDateCompare { Before = -1, equal = 0, after = 1 };
enDateCompare compareDates(strDate date1, strDate date2) {
	if (isDate1BeforeDate2(date1, date2))
		return enDateCompare::Before;

	if (isDate1EqualDate2(date1, date2))
		return enDateCompare::equal;

	//if (isDate1AfterDate2(date1, date2))
	//    return enDateCompare::after;

	return enDateCompare::after;

}
bool isDate1BetweenDate2AndDate3(strDate date1, strDate date2, strDate date3) {
	return (isDate1AfterDate2(date1, date2) && isDate1BeforeDate2(date1, date3));
}
bool isDate1BetweenDate2AndDate3_Inclusive(strDate date1, strDate date2, strDate date3) {
	return (!isDate1BeforeDate2(date1, date2) && !isDate1AfterDate2(date1, date3));
}
short getTotalDaysFromBeginningOfTheYear(strDate date) {
	short totalDays = date.day;
	for (int i = 1; i < date.month; i++) {
		totalDays += getDaysInMonth(date.year, i);
	}
	return totalDays;
}
int getDifferenceInDays_fast(strDate date1, strDate date2, bool includeEndDay = false) {
	if (!isDate1BeforeDate2(date1, date2)) {
		return -1 * getDifferenceInDays_fast(date2, date1, includeEndDay);
	}
	int days = 0;
	while (date2.year > date1.year) {
		days += getNumberOfDaysInAYear(date1.year);
		date1.year++;
	}
	days += (getTotalDaysFromBeginningOfTheYear(date2) - getTotalDaysFromBeginningOfTheYear(date1));

	return includeEndDay ? days + 1 : days;
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

	return period;
}



bool hasOverLapFast(strPeriod period1, strPeriod period2) {
	return !((compareDates(period1.startDate, period2.endDate) == enDateCompare::after ||
		compareDates(period1.endDate, period2.startDate) == enDateCompare::Before));
}
bool hasOverLap(strPeriod period1, strPeriod period2) {
	strDate counter = period1.startDate;
	while (!isDate1BeforeDate2(period1.endDate, counter)) {
		if (isDate1BetweenDate2AndDate3_Inclusive(counter, period2.startDate, period2.endDate)) {
			return true;
		}
		counter = increaseDateByOneDay(counter);
	}
	return false;
}

bool isDateInPeriod(strDate date, strPeriod period) {
	return isDate1BetweenDate2AndDate3_Inclusive(date, period.startDate, period.endDate);
}

int countOverlapDays(strPeriod period1, strPeriod period2) {
	if (!hasOverLapFast(period1, period2)) {
		return 0;
	}
	int countDays = 0;
	strDate currentDate = period1.startDate;
	while (!isDate1BeforeDate2(period1.endDate, currentDate)) {
		if (isDateInPeriod(currentDate, period2)) {
			countDays++;
		}
		currentDate = increaseDateByOneDay(currentDate);
	}
	return countDays;
}
int periodLengthInDays(strPeriod Period, bool IncludeEndDate = false) {
	return getDifferenceInDays_fast(Period.startDate, Period.endDate, IncludeEndDate);
}

int countOverlapDays_middleFast(strPeriod Period1, strPeriod Period2) {
	if (!hasOverLapFast(Period1, Period2)) return 0;

	int Period1Length = periodLengthInDays(Period1, true);
	int Period2Length = periodLengthInDays(Period2, true);
	int OverlapDays = 0;
	strDate temp;
	if (Period1Length < Period2Length) {
		temp = Period1.startDate;
		while (!isDate1AfterDate2(temp, Period1.endDate)) {
			if (isDateInPeriod(temp, Period2))
				OverlapDays++;
			temp = increaseDateByOneDay(temp);
		}
	}
	else {
		temp = Period2.startDate;
		while (!isDate1AfterDate2(temp, Period2.endDate)) {
			if (isDateInPeriod(temp, Period1))
				OverlapDays++;
			temp = increaseDateByOneDay(temp);
		}
	}
	return OverlapDays;
}

int countOverlapDays_fast(strPeriod period1, strPeriod period2) {
	if (!hasOverLapFast(period1, period2)) {
		return 0;
	}
	strDate overlapStart = (isDate1BeforeDate2(period1.startDate, period2.startDate)) ? period2.startDate : period1.startDate;
	strDate overlapEnd = (isDate1BeforeDate2(period1.endDate, period2.endDate)) ? period1.endDate : period2.endDate;

	return getDifferenceInDays_fast(overlapStart, overlapEnd, true);
}

int main()
{
	cout << "Enter Period 1 :\n";
	strPeriod period1 = readPeriod();
	cout << "Enter Period 2 :\n";
	strPeriod period2 = readPeriod();

	if (hasOverLapFast(period1, period2)) {
		cout << "Counter of overlap days is : " << countOverlapDays_fast(period1, period2) << endl;
		cout << "Counter of overlap days is : " << countOverlapDays_middleFast(period1, period2) << endl;
		cout << "Counter of overlap days is : " << countOverlapDays(period1, period2) << endl;

	}
	else {
		cout << "It is no overlap!! \n";
	}

	system("pause>0");
	return 0;
}
