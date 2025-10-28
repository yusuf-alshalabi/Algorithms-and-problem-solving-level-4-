
/*

Question (19) :
Write a program that reads :
-Date1.
-Date2.
Then create a function to calculate the difference in days.

Note : If Date2 is less than Date1
	   print the result as a negative.

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

//void  SwapDates(strDate& Date1, strDate& Date2){
//strDate TempDate;  
//
//TempDate.year = Date1.year;
//TempDate.month = Date1.month;
//TempDate.day = Date1.day;
//
//Date1.year = Date2.year;
//Date1.month = Date2.month;
//Date1.day = Date2.day;
//
//Date2.year = TempDate.year;
//Date2.month = TempDate.month;
//Date2.day = TempDate.day;
//}
//
//int GetDifferenceInDays(strDate Date1, strDate Date2, bool IncludeEndDay = false) {
//    int Days = 0; 
//    short SawpFlagValue = 1;
//    if (isDate1BeforeDate2(Date1, Date2)) {
//                SwapDates(Date1, Date2);     
//                SawpFlagValue = -1;   
//    }
//    while (isDate1BeforeDate2(Date1, Date2)){
//        Days++;
//        Date1 = increaseDateByOneDay(Date1);  
//    } return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
//}

int getDifferenceInDays(const strDate& date1, const strDate& date2, bool includeEndDay = false) {
	if (!isDate1BeforDate2(date1, date2)) {
		return -1 * getDifferenceInDays(date2, date1, includeEndDay);
	}
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


	cout << "The Number of Days between Date(1) and Date(2) is : "
		<< getDifferenceInDays(date1, date2) << " Day(s)\n";



	cout << "The Number of Days between Date(1) and Date(2) (Including End day) is : "
		<< getDifferenceInDays(date1, date2, true) << " Day(s)\n";


	system("pause>0");
	return 0;
}
