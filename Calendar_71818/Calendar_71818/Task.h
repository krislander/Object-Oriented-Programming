#pragma once
#include "stdafx.h"
#include "Time.h"
#include "Date.h"
#include "Types.h"


class Task
{
private:
	char* title;
	char* description;
	Time start;
	Time end; 
	Date date;
	
	Types type;
	static int id;

	void copyTask(const Task& other)
	{
		this->title = new char[strlen(other.title) + 1];
		strcpy_s(this->title, strlen(other.title) + 1, other.title);
		this->description = new char[strlen(other.description) + 1];
		strcpy_s(this->description, strlen(other.description) + 1, other.description);
		this->start = other.start;
		this->end = other.end;
		this->type = other.type;
		this->date = other.date;
	}
	virtual void destroy()
	{
		delete[] this->title;
		delete[] this->description;
	}
public:
	enum Types
	{
		Default,
		Business,
		Education,
		Entertainment
	};

	//tuka shte ima print

	Task();
	Task(const char* title, const char* description, Time start, Time end, Types type);
	Task(const Task& other);
	Task& operator=(const Task& other);
	~Task();
};

int Task::id = 0;

Task::Task()
{
	this->title = new char[1];
	strcpy_s(this->title, 1, "");
	this->description = new char[1];
	strcpy_s(this->description, 1, "");
	this->type = Default;
}

Task::Task(const char * title, const char * description, Time start, Time end, Types type)
{
	this->title = new char[strlen(title) + 1];
	strcpy_s(this->title, strlen(title) + 1, title);
	this->description = new char[strlen(description) + 1];
	strcpy_s(this->description, strlen(description) + 1, description);
	this->start = start;
	this->end = end;
	this->type = type;
	this->id++;
}

Task::Task(const Task & other)
{
	this->copyTask(other);
}

Task & Task::operator=(const Task & other)
{
	if (this != &other)
	{
		destroy();
		this->copyTask(other);
	}
	return *this;
}


Task::~Task()
{
	this->destroy();
}

