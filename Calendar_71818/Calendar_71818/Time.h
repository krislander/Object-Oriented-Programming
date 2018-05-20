#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Time
{
private:

	int hours;
	int minutes;

public:
	Time();
	Time(const int hours, const int minutes);
	Time(const Time& other);
	Time& operator-(const Time& other);
	bool IsValidTime(int hours, int minutes);
	const int getHours() const;
	const int getMinutes() const;
	void setHours(int hours);
	void setMinutes(int minutes);
	void print();
	void write(ofstream& stream);
	void read(ifstream& stream);
};

Time::Time()
{
	this->hours = 0;
	this->minutes = 0;
}

Time::Time(const int hours, const int minutes)
{
	if (hours >= 0 && hours <= 23)
		this->hours = hours;
	if (minutes >= 0 && minutes <= 59)
		this->minutes = minutes;
}

Time::Time(const Time& other)
{
	if (other.hours >= 0 && other.hours <= 23)
		this->hours = other.hours;
	if (other.minutes >= 0 && other.minutes <= 23)
		this->minutes = other.minutes;
}

Time & Time::operator-(const Time & other)
{
	int divOfHours = this->hours - other.hours;
	int divOfMinutes = this->minutes - other.minutes;

	Time newTime;

	if (divOfMinutes < 0)
	{
		if (divOfHours <= 0)
			newTime.setHours(24 + divOfHours - 1);
		else
			newTime.setHours(divOfHours - 1);
		newTime.setMinutes(60 + divOfMinutes);
	}
	else
	{
		if (divOfHours < 0)
			newTime.setHours(24 + divOfHours);
		else
			newTime.setHours(divOfHours);
		newTime.setMinutes(divOfMinutes);
	}
	return newTime;
}

bool Time::IsValidTime(int hours, int minutes)
{
	return(hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59);
}

const int Time::getHours() const
{
	return this->hours;
}

const int Time::getMinutes() const
{
	return this->minutes;
}

void Time::setHours(int hours)
{
	if (hours >= 0 && hours <= 23)
		this->hours = hours;
	else
		this->hours = 0;
}

void Time::setMinutes(int minutes)
{
	if (minutes >= 0 && minutes <= 59)
		this->minutes = minutes;
	else
		this->minutes = 0;
}

void Time::print()
{
	if (hours < 10 && minutes < 10)
	{
		cout << "0" << hours << ":" << "0" << minutes << endl;
	}
	else if (hours < 10 && minutes >= 10)
	{
		cout << "0" << hours << ":" << minutes << endl;
	}
	else if (hours >= 10 && minutes < 10)
	{
		cout << hours << ":" << "0" << minutes << endl;
	}
	else if (hours >= 10 && minutes >= 10)
	{
		cout << hours << ":" << minutes << endl;
	}
}

void Time::write(ofstream & stream)
{
	stream << this->hours;
	stream << this->minutes;
}

void Time::read(ifstream & stream)
{
	stream >> this->hours;
	stream >> this->minutes;
}
