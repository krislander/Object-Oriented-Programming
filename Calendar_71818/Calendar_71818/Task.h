#pragma once
#include "stdafx.h"
#include <iostream>
#include <cstring>
#include "Time.h"
#include "Date.h"


class Task
{
private:
	char* title;
	char* description;
	Time start;
	Time end; //otdelen klas za vremeto kadeto pravq proverka dali e validno
	Date date;

	//trqbva da se dobavi data?????
	enum Types
	{
		Default,
		Business,
		Education,
		Entertainment
	};
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
	}
	virtual void destroy()
	{
		delete[] this->title;
		delete[] this->description;
	}
public:

	//tuka shte ima print

	Task();
	Task(const char* title, const char* description, Time start, Time end);
	Task(const Task& other);
	Task& operator=(const Task& other);
	~Task();
};

Task::Task()
{
	this->title = new char[15];
	strcpy_s(this->title, 15, "basic title");
	this->description = new char[15];
	strcpy_s(this->description, 15, "this is text");
	Time start2;
	Time end2;
	this->start = start2;
	this->end = end2;
	this->type = Default;
	this->id = 0;
}

Task::Task(const char * title, const char * description, Time start, Time end)
{
	this->title = new char[strlen(title) + 1];
	strcpy_s(this->title, strlen(title) + 1, title);
	this->description = new char[strlen(description) + 1];
	strcpy_s(this->description, strlen(description) + 1, description);
	this->start = start;
	this->end = end;
	this->type = type;
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

