#pragma once
#include "Task.h"
#include "LList.h"

class Day
{
private:
	LList<Task> tasks;

	//za vseki task ima funkciq getDate()
public:
	void addTask(Task task);
	void removeTask(Task task);
	//getter za day month year otdelno ot Date
	//nova funkciq za printche
	//sravnqvane
	/*for (int i = 0; i < currentSize; i++)
	{
		if (this->tasks[i].getDay == userinput[0] && i t.n)
		{

		}
	}*/
};

void Day::addTask(Task task)
{
	this->tasks.push_back(task);
}

void Day::removeTask(Task task)
{
	this->tasks.removeAllocc(task);
}
