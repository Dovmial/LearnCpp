#include"Time.h"
#include<iostream>
using std::cout;
#include <iomanip>
using std::setfill;
using std::setw;


Time::Time(int hr, int min, int sec)
{
	setTime(hr, min, sec);
}

Time &Time::setTime(int h, int m, int s)
{
	setHour(h);
	setMinute(m);
	setSecond(s);
	return *this; //каскадирование
}
Time &Time::setHour(int h)
{
	hour = (h >= 0 && h < 24) ? h : 0;
	return *this;
}
Time &Time::setMinute(int m)
{
	minute = (m >= 0 && m < 60) ? m : 0;
	return *this;
}
Time &Time::setSecond(int s)
{
	second = (s >= 0 && s < 60) ? s : 0;
	return *this;
}
int Time::getHour() const
{
	return hour; 
}
int Time::getMinute() const
{
	return minute;
}
int Time::getSecond() const
{
	return second;
}

void Time::printUniversal() const
{
	cout << setfill('0') << setw(2) << getHour() << ':'
		<< setw(2) << getMinute() << ':' << setw(2)
		<< getSecond();
}

void Time::printStandard() const
{
	cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
		<< ':' << setfill('0') << setw(2) << getMinute()
		<< ':' << setw(2) << getSecond()
		<< (hour < 12 ? " am" : " pm");
}

