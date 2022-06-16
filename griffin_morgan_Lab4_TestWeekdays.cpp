/*
Griffin Morgan
W10077316
CSC 112L Spring 2022
Lab:  Rework of Lab 3 to Include Operation Overload
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;
using std::abs;

string dayname[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

class Weekday
{
	int day_num;

public:
	Weekday(int n)
	{
		day_num = n;
	}

	Weekday operator+(int n)
	{
		Weekday temp((day_num + n) % 7);
		return temp;
	}

	Weekday operator-(int n)
	{
		Weekday temp((7 + (day_num - n % 7)) % 7);
		return temp;
	}

	friend ostream& operator<<(ostream& out, const Weekday& w)
	{
		out << dayname[w.day_num];
		return out;
	}

	string to_name()
	{
		return dayname[day_num];
	}
}
;

int main()
{
	Weekday w1(5); //Enter which day of the week
	cout << "Current Day: " << w1 << endl;
	w1 = w1 + 5;
	cout << "Add 5 Days: " << w1 << endl;
	w1 = w1 - 10;
	cout << "Subtract 10 Days: " << w1 << endl;

	return 0;

}