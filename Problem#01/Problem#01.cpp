

/*

Question (1) :

Write a program to read a number and print the text of that number.

*/

#include <iostream>


using namespace std;

string trim(string s) {
	while (!s.empty() && s.front() == ' ') s.erase(s.begin());
	while (!s.empty() && s.back() == ' ') s.pop_back();
	return s;
}

string Units[] = { "","One" ,"Two","Three","Four","Five","Six","Seven","Eight","Nine" };
string Teens[] = { "","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
string Tens[] = { "","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
string Groups[] = { "","Thousand","Million","Billion" };

string getTextOfTheGroupNumber(int n, int group) {
	if (n == 0) return "";

	int temp = n % 10;
	n = n / 10;
	int number1 = temp;
	temp = n % 10;
	n = n / 10;
	int number2 = temp;
	temp = n % 10;
	n = n / 10;
	int number3 = temp;

	string  textOfTheGroupNumber = "";
	if (number2 == 1) {
		if (number3 != 0) {
			textOfTheGroupNumber = Units[number3] + " Hundred" + " ";
		}
		textOfTheGroupNumber = textOfTheGroupNumber +
			Teens[number1] + " ";
	}
	else {
		if (number1 != 0) {
			textOfTheGroupNumber = Units[number1] + " ";
		}
		if (number2 != 0) {
			textOfTheGroupNumber = Tens[number2] + " " + textOfTheGroupNumber;
		}
		if (number3 != 0) {
			textOfTheGroupNumber = Units[number3] + " Hundred" + " " + textOfTheGroupNumber;
		}
	}
	if (textOfTheGroupNumber != "")
		return textOfTheGroupNumber + Groups[group] + " ";

	return "";
}

string getTextOfNumber(int number) {
	if (number == 0) {
		return "Zero";
	}
	int counter = 0;
	int temp = 0;
	bool isNegative = false;
	string text = "";
	if (number < 0) {
		number = -1 * number;
		isNegative = true;
	}
	while (number > 0) {
		temp = number % 1000;
		number /= 1000;
		text = getTextOfTheGroupNumber(temp, counter) + text;
		counter++;
	}
	text = trim(text);
	if (isNegative) {
		return "Negative " + text;
	}
	else {
		return text;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////Second Method : Using Recursive////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
string GetTextOfNumber(int number) {
	if (number == 0) {
		return "Zero";
	}
	else if (number < 0) {
		return "Negative " + GetTextOfNumber(number * -1);
	}
	string text = "";

	if (number < 10) {
		text += Units[number];
	}
	else if (number >= 11 && number <= 19) {
		text += Teens[number - 10];
	}
	else if (number < 100 && number % 10 == 0) {
		text += Tens[number / 10];

	}
	else if (number < 100) {
		int numTens = number / 10;
		int remain = number % 10;
		text = text + Tens[numTens] + " " + GetTextOfNumber(remain);
	}
	else if (number < 1000) {
		int nunHundreds = number / 100;
		int remain = number % 100;
		text = text + Units[nunHundreds] + " Hundred";
		if (remain > 0) {
			text = text + " " + GetTextOfNumber(remain);
		}
	}
	else if (number < 1000000) {
		int nunThousands = number / 1000;
		int remain = number % 1000;
		text = text + GetTextOfNumber(nunThousands) + " Thousand";
		if (remain > 0) {
			text = text + " " + GetTextOfNumber(remain);
		}
	}
	else if (number < 1000000000) {
		int nunMillions = number / 1000000;
		int remain = number % 1000000;
		text = text + GetTextOfNumber(nunMillions) + " Million";
		if (remain > 0) {
			text = text + " " + GetTextOfNumber(remain);
		}
	}
	else if (number < 1000000000000) {
		int nunBillions = number / 1000000000;
		int remain = number % 1000000000;
		text = text + GetTextOfNumber(nunBillions) + " Billion";
		if (remain > 0) {
			text = text + " " + GetTextOfNumber(remain);
		}
	}

	return text;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

int readNumber() {
	int number;
	cout << "Enter the number : ";
	cin >> number;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Please enter a number.\n";
		return readNumber();
	}

	return number;
}


int main()
{
	int number = readNumber();
	cout << getTextOfNumber(number) << ".\n";
	cout << GetTextOfNumber(number) << ".\n";

	system("pause>0");
	return 0;
}
