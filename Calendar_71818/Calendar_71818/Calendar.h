#pragma once
#include "Task.h"
#include "Date.h"
#include "Month.h"

class Calendar
{
private:
	Month* months;
	void copy(const Calendar& other)
	{
		this->months = new Month[12];
		for (int i = 0; i < 12; i++)
		{
			this->months[i] = other.months[i];
		}
	}
	void destroy()
	{
		delete[] this->months;
	}
public:
	void print();

	Calendar();
	Calendar(const Calendar& other);
	Calendar& operator=(const Calendar& other);
	~Calendar();
};

void Calendar::print()
{
	for (int i = 0; i < 12; i++)
	{
		this->months[i].print();
	}
}

Calendar::Calendar()
{
	this->months = new Month[12];
	
	for (int i = 0; i < 12; i++)
	{
		if (i==3 && i==5 && i==8 && i==10)
		{
			Month temp(30);
			this->months[i] = temp;
		}
		else if (i==1)
		{
			Month temp(28);
			this->months[i] = temp;
		}
		else
		{
			Month temp(31);
			this->months[i] = temp;
		}
	}
}

Calendar::Calendar(const Calendar & other)
{
	this->copy(other);
}

Calendar & Calendar::operator=(const Calendar & other)
{
	if (this != &other)
	{
		this->destroy();
		this->copy(other);
	}

	return *this;
}

Calendar::~Calendar()
{
	this->destroy();
}




