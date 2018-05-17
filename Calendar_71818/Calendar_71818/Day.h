#pragma once
#include "Task.h"
#include "Vector.h"

class Day
{
private:
	Task** tasks;
	size_t currentSize;
	size_t capacity;

	//za vseki task ima funkciq getDate()

	void copy(const Day& other)
	{
		this->tasks = new Task*[other.capacity];
		for (size_t i = 0; i < other.currentSize; i++)
		{
			this->tasks[i] = other.tasks[i];
		}
		this->currentSize = other.currentSize;
		this->capacity = other.capacity;
	}
	void destroy()
	{
		delete[] this->tasks;
	}
	void resize()
	{
		this->capacity = this->capacity * 2 + 1;
		Task** temp = new Task*[this->capacity];
		for (int i = 0; i < currentSize; i++)
		{
			temp[i] = this->tasks[i];
		}
		delete[] this->tasks;
		this->tasks = temp;
	}
public:
	void addTask(Task* task);
	void removeTask(Task* task);
	//write
	//read
	//getter za day month year otdelno ot Date
	//nova funkciq za printche
	//sravnqvane
	/*for (int i = 0; i < currentSize; i++)
	{
		if (this->tasks[i].getDay == userinput[0] && i t.n)
		{

		}
	}*/
	

	Day();
	Day(const Day& other);
	Day& operator= (const Day& other);
	~Day();
};

void Day::addTask(Task* task)
{
	if (this->currentSize >= this->capacity)
	{
		this->resize();
	}
	this->tasks[this->currentSize++] = task;
}

void Day::removeTask(Task* task)
{
	size_t index = -1;
	for (size_t i = 0; i < this->currentSize; i++)
	{
		if (this->tasks[i] == task)
		{
			index = i;
			break;
		}
	}
	if (index == -1) return;

	Task** temp = new Task*[this->capacity];
	for (int i = 0, j = 0; i < this->currentSize; i++, j++)
	{
		if (i == index) ++i;
		temp[j] = this->tasks[i];
	}
	this->destroy();
	this->tasks = temp;
	this->currentSize--;
}

Day::Day()
{
	this->tasks = new Task*[this->capacity];
	this->currentSize = 0;
	this->capacity = 0;
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
