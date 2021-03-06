// Calendar_71818.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Calendar.h"
#include "Task.h"
#include <fstream>
#include "Engine.h"


int main()
{
	Calendar first;
	Engine start;

	std::cout << "Welcome to your TASK CALENDAR. From here you can add new tasks, remove old tasks and check what tasks you have each day. " << std::endl;
	std::cout << "Commands: " << std::endl;
	std::cout << "1 - Add a task " << std::endl;
	std::cout << "2 - Remove a task " << std::endl;
	std::cout << "3 - Search tasks by date " << std::endl;
	std::cout << "4 - Exit " << std::endl;

	int input;
	std::cin >> input;
	while (input != 4)
	{
		if (input == 1)
		{
			start.addNewTask(first);
		}
		else if (input == 2)
		{
			start.removeTask(first);
		}
		else if (input == 3)
		{
			cout << "Choose a date to see what tasks you have there currently: ";
			int day, month, year;
			std::cin >> day >> month >> year;
			Date inputDate(day, month, year);
			if (!inputDate.valid(day,month,year))
			{
				std::cout << "Invalid Date!" << std::endl;
			}
		}
		else
		{
			std::cout << "Try again! " << std::endl;
			std::cout << "Commands: " << std::endl;
			std::cout << "1 - Add a task " << std::endl;
			std::cout << "2 - Remove a task " << std::endl;
			std::cout << "3 - Search tasks by date " << std::endl;
			std::cout << "4 - Exit " << std::endl;
		}
		std::cin >> input;
	}
	std::cout << "Bye" << std::endl;

    return 0;
}

