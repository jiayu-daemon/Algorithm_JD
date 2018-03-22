

#ifndef TIME_H
#define TIME_H


class Time
{
public:
	Time( int = 0, int = 0, int = 0); // default constructor

	// setTime functions (the Time & return types enable cascading)
	Time & setTime(int, int, int); //set hour, minute, second
	Time & setHour(int); // set hour
	Time & setMinute(int); // set minute
	Time & setSecond(int); // set second

	//get functions (normal declared const)
	int getHour() const; // return hour
	int getMinute() const; // 
	int getSecond() const;

	//print functions 
	void printUniversal() const; //
	void printStandard() const;  //
private:
	int hour;
	int minute;
	int second;
};



#endif

