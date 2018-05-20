#pragma once
#include "Task.h"
#include "LList.h"

class Day
{
private:
	Task** tasks;
	size_t currentTasks;
	size_t capacity;

	void copy(const Day& other)
	{
		this->tasks = new Task*[other.capacity];
		for (int i = 0; i < other.currentTasks; i++)
		{
			this->tasks[i] = other.tasks[i];
		}
		this->currentTasks = other.currentTasks;
		this->capacity = other.capacity;
	}
	void destroy()
	{
		for (int i = 0; i < currentTasks; i++)
		{
			delete[] this->tasks[i];
		}
		delete[] this->tasks;
	}
	void resize()
	{
		this->capacity = 2 * this->capacity + 1;
		Task** temp = new Task*[this->capacity];
		for (int i = 0; i < currentTasks; i++)
		{
			temp[i] = this->tasks[i];
		}
		delete[] this->tasks;
		this->tasks = temp;
	}
public:
	Day();
	Day(const Day& other);
	Day& operator=(const Day& other);
	~Day();

	void addTask(Task*& task);
	void removeTask(Task*& task);
	void printAllTasks() const;
};

Day::Day()
{
	this->capacity = 1;
	this->tasks = new Task*[this->capacity];
	this->currentTasks = 0;
}

Day::Day(const Day & other)
{
	this->copy(other);
}

Day & Day::operator=(const Day & other)
{
	if (this != &other)
	{
		this->destroy();
		this->copy(other);
	}

	return *this;
}

Day::~Day()
{
	this->destroy();
}

void Day::addTask(Task*& task)
{
	if (this->currentTasks >= this->capacity)
	{
		this->resize();
	}

	this->tasks[this->currentTasks++] = task;
}

void Day::removeTask(Task*& task)
{
	size_t index = -1;
	for (size_t i = 0; i < this->currentTasks; i++)
	{
		if (task == this->tasks[i])
		{
			index = i;
			break;
		}
	}
	if (index == -1) return;

	Task** temp = new Task*[this->capacity];
	for (size_t i = 0, j = 0; i < this->currentTasks; i++, j++)
	{
		if (i == index) ++i;
		temp[j] = this->tasks[i];
	}
	this->destroy();
	this->tasks = temp;
	this->currentTasks--;
}

void Day::printAllTasks() const
{
	for (int i = 0; i < currentTasks; i++)
	{
		this->tasks[i]->print();
	}
}
