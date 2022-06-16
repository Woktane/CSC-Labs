/*
Griffin Morgan
Lab: Days of the Week
*/

#include<iostream>
#include<cmath>

using namespace std;

class Weekday
{
    string day;
    string days[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
public:
    void getday();
    string display();
    string afterday();
    string beforeday();
    string changeday(int);
};
void Weekday::getday()
{
    cout << "Enter the day: \n";
    cin >> day;
}
string Weekday::display()
{
    return day;
}
string Weekday::afterday()
{
    int i = 0;
    string d = day;
    while (1)
    {
        if (days[i % 7] == day)
        {
            d = days[(i + 1) % 7];
            break;
        }
        i++;
    }
    return d;
}
string Weekday::beforeday()
{
    int i = 0;
    string d = day;
    while (1)
    {
        if (days[i % 7] == day)
        {
            if ((i - 1) < 0)
            {
                i = 7 + i - 1;
                d = days[i % 7];
                break;
            }
            else
            {
                d = days[(i - 1) % 7];
                break;
            }
        }
        i++;
    }
    return d;
}
string Weekday::changeday(int n)
{
    int i = 0;
    string d = day;
    while (1)
    {
        if (days[i % 7] == day)
        {
            if ((i + n) < 0)
            {
                i = 7 + i + n;
                d = days[i % 7];
                break;
            }
            else
            {
                d = days[(i + n) % 7];
                break;
            }

        }
        i++;
    }
    return d;
}
int main()
{
    Weekday ob;
    ob.getday();
    int n;
    cout << endl << "Today is: " << ob.display();
    cout << endl << "The day after " << ob.display() << " is: " << ob.afterday();
    cout << endl << "The day before " << ob.display() << " is: " << ob.beforeday();
    cout << endl << "Enter a number that will tell you how many days, numerically, how far away the day is. Use negative for before.: \n";

    //A
    cin >> n;
    if (n > 0)
    {
        cout << endl << n << " days after " << ob.display() << " is: \n" << ob.changeday(n);
    }
    if (n < 0)
    {
        cout << endl << -n << " days before " << ob.display() << " is: \n" << ob.changeday(n);
    }
    return 0;
}