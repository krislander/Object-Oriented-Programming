#pragma once
#include "stdafx.h"
#include "Calendar.h"
#include "BusinessTask.h"
#include "EntertainmentTask.h"
#include "EducationalTask.h"


class Engine
{
public:
	void addNewTask(Calendar &calendar);
	void removeTask(Calendar &calendar);
};

void Engine::addNewTask(Calendar & calendar)
{
	int type = 0;
	int month = 0;
	int day = 0;

	while (type < 1 || type >3)
	{
		std::cout << "What type of task do you want?" << std::endl;
		std::cout << "Enter 1 for Business Task\n   Enter 2 for University task\n   Enter 3 for Entertainment Task: ";
		std::cin >> type;
	}
	while (month < 1 || month>12)
	{
		std::cout << "Enter the number of the month of your task: ";
		std::cin >> month;
	}
	if (month == 2)
	{
		while (day < 1 || day>28)
		{
			std::cout << "Enter the date of the task: ";
			std::cin >> day;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		while (day < 1 || day>30)
		{
			std::cout << "Enter the date of the task: ";
			std::cin >> day;
		}
	}
	else
	{
		while (day < 1 || day>31)
		{
			std::cout << "Enter the date of the task: ";
			std::cin >> day;
			std::cin.ignore();
		}
	}
	if (type == 1)
	{
		Day one;
		BusinessTask temp;
		temp.initializeTask(day,month,type);
		Task* tempp = new BusinessTask(temp);
		one.addTask(tempp);
		delete tempp;
	}
	else if (type == 2)
	{
		Day one;
		EducationalTask temp;
		temp.initializeTask(day, month, type);
		Task* tempp = new EducationalTask(temp);
		one.addTask(tempp);
		delete tempp;
	}
	else if (type == 3)
	{
		Day one;
		EntertainmentTask temp;
		temp.initializeTask(day, month, type);
		Task* tempp = new EntertainmentTask(temp);
		one.addTask(tempp);
		delete tempp;
	}
}
