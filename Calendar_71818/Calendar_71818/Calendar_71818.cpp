// Calendar_71818.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Date.h"


int main()
{
	int day;
	int month;
	int year;
	Date inputDate(day,month,year);
	cout << "Choose a date to see what tasks you have there currently: ";
	std::cin >> day >> month>> year;

	//LetTheGameBegin();
    return 0;
}

