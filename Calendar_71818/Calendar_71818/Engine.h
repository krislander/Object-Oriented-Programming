#pragma once
#include "stdafx.h"
#include "Calendar.h"
#include "BusinessTask.h"
#include "EntertainmentTask.h"
#include "EducationalTask.h"


class Engine
{
	void addNewTask(Calendar &calendar);
	void removeTask(Calendar &calendar);

};

void Engine::addNewTask(Calendar & calendar)
{
	int type = 0;

	while (type < 1 || type >3)
	{
		std::cout << "What type of task do you want?" << std::endl;
		std::cout << "Enter 1 for Business Task\n   Enter 2 for University task\n   Enter 3 for Entertainment Task: ";
		std::cin >> type;
	}
	if (type == 1)
	{
		Day temp;
		BusinessTask newTask;
		
		temp.addTask(newTask);
	}
}
