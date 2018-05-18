#pragma once
#include "Task.h"
#include "Date.h"
#include "LList.h"

class Calendar
{
private:
	char* description;
	LList<Task> tasks;

	void copy(const Calendar& other)
	{
		this->description = new char[strlen(other.description) + 1];
		strcpy_s(this->description, strlen(other.description) + 1, other.description);
	}
	void destroy()
	{
		delete[] this->description;
	}
public:
	void addTask(Task task);
	void removeTask(Task task);
	void printNeededTasks();
	const Task getDateOfTask() const;
	//teq laina trqbva da gi sravnq

	Calendar();
	Calendar(const Calendar& other);
	Calendar operator=(const Calendar& other);
	~Calendar();


};

void Calendar::addTask(Task task)
{
	this->tasks.push_back(task);
}
void Calendar::removeTask(Task task)
{
	this->tasks.removeAllocc(task);
}

void Calendar::printNeededTasks()
{
	for (int i = 0; i < tasks.getNumberOfElements(); i++)
	{
		if (true)
		{

		}
	}
}

