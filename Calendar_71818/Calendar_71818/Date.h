#pragma once
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int day, int month, int year);
	bool valid(const int day, const int month, const int year);
	void print();
	const int getDay() const;
	const int getMonth() const;
	const int getYear() const;
	void write(ofstream& stream);
	void read(ifstream& stream);

};

Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 1990;
}

Date::Date(int day, int month, int year)
{
	if (!valid(day, month, year))
	{
		cout << "Invalid date input!" << endl;
	}
	else
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
}

bool Date::valid(const int day, const int month, const int year)
{
	if (year < 2018)
		return false;
	if (month > 12 || month < 1)
		return false;
	if (day > 31 || day < 1)
		return false;
	if ((day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)))
		return false;
	if (day == 30 && month == 2)
		return false;
	if ((day == 29 && month == 2) && !(((year - 1900) % 4 == 0)))
		return false;
	if (year >2000) 
	{
			if ((day == 29 && month == 2) && !(((year - 2000) % 4 == 0)))
				return false;
	}
		return true;
}

void Date::print()
{
	if (day < 10)
	{
		if (month < 10)
		{
			cout << "Date: "<<"0" << day << ". " << "0" << month << ". " << year << endl;
		}
		cout << "Date: " << day << ". " << "0" << month << ". " << year << endl;
	}
	cout << "Date: " << day << ". "  << month << ". " << year << endl;
}

const int Date::getDay() const
{
	return this->day;
}

const int Date::getMonth() const
{
	return this->month;
}

const int Date::getYear() const
{
	return this->year;
}

void Date::write(ofstream & stream)
{
	stream << this->day;
	stream << this->month;
	stream << this->year;
}

void Date::read(ifstream & stream)
{
	stream >> this->day;
	stream >> this->month;
	stream >> this->year;
}
