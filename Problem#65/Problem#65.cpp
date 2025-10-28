
/*

Questione (65) :
Write a program to read Date
And Write function to formate that Date.

*/

#include <iostream>
#include <vector>
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

string replaceWordInString(string S1, string StringToReplace, string sRepalceTo) {
	short pos = S1.find(StringToReplace);
	while (pos != std::string::npos) {
		S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
		pos = S1.find(StringToReplace);//find next 
	}
	return S1;
}

strDate stringToDate(string DateString) {
	vector<string> vDate = splitString(DateString, "/");
	strDate Date;
	Date.day = stoi(vDate[0]);
	Date.month = stoi(vDate[1]);
	Date.year = stoi(vDate[2]);
	return Date;
}

string formateDate(strDate Date, string DateFormat = "dd/mm/yyyy") {
	string FormattedDateString = "";
	FormattedDateString = replaceWordInString(DateFormat, "dd", to_string(Date.day));
	FormattedDateString = replaceWordInString(FormattedDateString, "mm", to_string(Date.month));
	FormattedDateString = replaceWordInString(FormattedDateString, "yyyy", to_string(Date.year));
	return  FormattedDateString;
}

string readStringDate(string Message) {
	string DateString;
	cout << Message;
	getline(cin >> ws, DateString);
	return DateString;
}

int main()
{
	string DateString = readStringDate("\nPlease Enter Date dd/mm/yyyy? ");
	strDate Date = stringToDate(DateString);
	cout << "\n" << formateDate(Date) << "\n";
	cout << "\n" << formateDate(Date, "yyyy/dd/mm") << "\n";
	cout << "\n" << formateDate(Date, "mm/dd/yyyy") << "\n";
	cout << "\n" << formateDate(Date, "mm-dd-yyyy") << "\n";
	cout << "\n" << formateDate(Date, "dd-mm-yyyy") << "\n";
	cout << "\n" << formateDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";
	system("pause>0");
	return 0;
}
