#pragma once
#include "Day.h"
#include "LList.h"

class Month
{
private:
	LList<Day> days;
public:
	bool IsValidDaysInMonth(size_t currentSize);
	//void write
	//void read
	//dali trqbva da ima addDate i removeDate

	Month();
	Month(const Month& other);
	Month& operator= (const Month& other);
	~Month();
};

