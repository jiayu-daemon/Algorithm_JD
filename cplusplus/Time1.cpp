#include <iostream>
#include <iomanip>
#include "Time1.h"

using namespace std;

Time::Time( int hr, int min, int sec)
{
	setTime(hr,min,sec);
}

// set values of hour minute and second
Time &Time::setTime(int h, int m, int s)
{
	setHour(h);
	setMinute(m);
	setSecond(s);

	return *this;
}

//set hour
Time & Time::setHour(int h)
{
	hour = (h >= 0 && h < 24)? h:0; // validate hour
	return *this; // enables cascading
}


// set minute value
Time & Time::setMinute(int m)
{
	minute = (m >= 0 && m < 60)? m : 0; // valid minute
	return *this;
}


//set second value
Time & Time::setSecond(int s)
{
	second = ( s >= 0 && s < 60)? s:0; // validate second
	return *this;
}


// get hour value
int Time::getHour() const
{
	return hour;
}

// get minute value
int Time::getMinute() const
{
	return minute;
}

// get second value
int Time::getSecond() const
{
	return second;
}

// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal() const
{
	cout << setfill('0') << setw(2) << hour << ":"
	<< setw(2) << minute << ":" << setw(2) << second;
}// end function printUniversal

// print Time in standard-time format(HH:MM:SS AM or PM)
void Time::printStandard() const
{
	cout << ( (hour ==0 || hour == 12) ? 12: hour%12) 
	<< ":" << setfill('0') << setw(2) << minute
	<< ":" << setw(2) << second << (hour < 12?"AM":"PM");
}// end function printSrandard








