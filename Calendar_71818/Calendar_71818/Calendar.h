#pragma once
#include "Month.h"
#include "Date.h"

class Calendar
{
private:
	char* description;
	Month* months;
	size_t currentSize;
	size_t capacity = 12;

	void copy(const Calendar& other)
	{
		this->description = new char[strlen(other.description) + 1];
		strcpy_s(this->description, strlen(other.description) + 1, other.description);
		this->months = new Month[this->capacity];
		for (int i = 0; i < currentSize; i++)
		{
			months[i] = other.months[i];
		}
		this->currentSize = other.currentSize;
		this->capacity = other.capacity;
	}
	void destroy()
	{
		delete[] this->description;
		delete[] this->months;
	}
public:
	Calendar();
	Calendar(const Calendar& other);
	Calendar operator=(const Calendar& other);
	~Calendar();


};