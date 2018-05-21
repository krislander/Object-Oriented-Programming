#pragma once
#include "Day.h"

class Month
{
private:
	Day * days;
	int currentSize;

	void copy(const Month& other)
	{
		this->days = new Day[other.currentSize];
		for (int i = 0; i < currentSize; i++)
		{
			this->days[i] = other.days[i];
		}
		this->currentSize = other.currentSize;
	}
	void destroy()
	{
		delete[] this->days;
	}
public:
	void print();
	void includeTask(int day, const Task* task);
	void removeTask(int day, const Task* task);

	Month();
	Month(int currentSize);
	Month(const Month& other);
	Month& operator=(const Month& other);
	~Month();
};


void Month::print()
{
	for (int i = 0; i < currentSize; i++)
	{
		this->days[i].printAllTasks();
	}
}

void Month::includeTask(int day, const Task* task)
{
	this->days[day].includeTask(task);
}

void Month::removeTask(int day, const Task* task)
{
}

Month::Month()
{
	this->currentSize = 0;
	this->days = 0;
}

Month::Month(int currentSize)
{
	this->currentSize = currentSize;
	this->days = new Day[currentSize];
}

Month::Month(const Month & other)
{
	this->copy(other);
}

Month & Month::operator=(const Month & other)
{
	if (this != &other)
	{
		this->destroy();
		this->copy(other);
	}

	return *this;
}

Month::~Month()
{
	this->destroy();
}

