
/*

Questione (63 & 64) :

Write a program to:
-Read Date String.
-Convert it to date structure.
-Print Day, Month, Year separately.
-Then convert Date Structure to string and print it on the screen.

Note: write the following functions:
-StringToDate.
-DateToString.

*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

struct strDate { short year; short month; short day; };
vector<string> splitString(string S1, string delim) {
	vector <string> split;

	short pos = 0;
	string sWord;

	while ((pos = S1.find(delim)) != std::string::npos) {
		sWord = S1.substr(0, pos);
		if (sWord != "") {
			split.push_back(sWord);
		}
		S1.erase(0, pos + delim.length());

	}

	if (S1 != "") {
		split.push_back(S1);
	}

	return split;
}

bool isLeapYear(short year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
short numberOfDaysInAMonth(short month, short year) {
	if (month < 1 || month>12) return  0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (isLeapYear(year) ? 29 : 28) : days[month - 1];
}

void printDate(strDate date) {
	cout << setw(2) << setfill('0') << date.day << "/";
	cout << setw(2) << setfill('0') << date.month << "/";
	cout << setw(4) << setfill('0') << date.year;

}

void printDateCard(strDate date) {
	cout << "Day :" << setw(2) << setfill('0') << date.day << endl;
	cout << "Month :" << setw(2) << setfill('0') << date.month << endl;
	cout << "Year :" << setw(4) << setfill('0') << date.year << endl;
}

strDate stringToDate(string DateString) {
	vector<string> vDate = splitString(DateString, "/");
	strDate Date;
	Date.day = stoi(vDate[0]);
	Date.month = stoi(vDate[1]);
	Date.year = stoi(vDate[2]);
	return Date;
}

string dateToString(strDate Date) {
	return to_string(Date.day) + "/" + to_string(Date.month) + "/" + to_string(Date.year);
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
		if (!cin.fail() && number >= 1 && number <= numberOfDaysInAMonth(year, month)) break;
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

string readDateString() {
	string date;
	cout << "Enter the date dd/mm/yyyy ? ";
	getline(cin >> ws, date);

	return date;
}

int main()
{
	string sDate = readDateString();
	strDate date = stringToDate(sDate);

	cout << endl;
	printDateCard(date);
	cout << "\nYou Entered : " << dateToString(date) << endl;

	system("pause>0");
	return 0;
}
