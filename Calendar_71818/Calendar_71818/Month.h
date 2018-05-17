#pragma once
#include "Day.h"
#include "LList.h"

class Month
{
private:
	LList<Day> days;
	size_t numberOfMonth;
	size_t daysPerMonth;
public:
	void DaysInMonth(size_t numbrOfMonth);
	void addDay(Day day);
	void removeDay(Day day);
	void print();
	//dobavqme addDay i removeDay

	Month();
	Month(LList<Day> days);
};

void Month::DaysInMonth(size_t numberOfMonth)
{
	if (numberOfMonth>=1 && numberOfMonth<=12)
	{
		switch (numberOfMonth)
		{
		case 1:
			this->daysPerMonth = 31;
			break;
		case 2:
			this->daysPerMonth = 28;
			break;
		case 3:
			this->daysPerMonth = 31;
			break;
		case 4:
			this->daysPerMonth = 30;
			break;
		case 5:
			this->daysPerMonth = 31;
			break;
		case 6:
			this->daysPerMonth = 30;
			break;
		case 7:
			this->daysPerMonth = 31;
			break;
		case 8:
			this->daysPerMonth = 31;
			break;
		case 9:
			this->daysPerMonth = 30;
			break;
		case 10:
			this->daysPerMonth = 31;
			break;
		case 11:
			this->daysPerMonth = 30;
			break;
		case 12:
			this->daysPerMonth = 31;
			break;
			default:
				break;
		}
	}	
	cout << "Incorrect input!" << endl;
}

void Month::addDay(Day day)
{
	this->days.push_back(day);
}

void Month::removeDay(Day day)
{
	this->days.removeAllocc(day);
}

Month::Month()
{
	this->numberOfMonth = 1;
	this->daysPerMonth = 31;
}

Month::Month(LList<Day> days)
{
	this->days = days;
}



