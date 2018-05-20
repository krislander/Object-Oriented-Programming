#pragma once
#include "stdafx.h"
#include "Time.h"
#include "Date.h"
#include <fstream>


class Task
{
public:
	enum Types
	{
		Default,
		Business,
		Education,
		Entertainment
	};
protected:
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

	void print();
	const Date getDate() const;
	virtual void write(ofstream& stream);
	virtual void read(ifstream& stream);
	virtual void addTask(Task& task) = 0;

	Task();
	Task(const char* title, const char* description, Time start, Time end, Types type, Date date);
	Task(const Task& other);
	Task& operator=(const Task& other);
	~Task();
};

int Task::id = 0;

void Task::print()
{
	cout << "Title of task: " << this->title << endl;
	cout << "Description: " << this->description << endl;
	cout << "Date: ";
	this->date.print();
	cout << "Start time: ";
	this->start.print();
	this->end.print();
	cout << "Number of task: " << this->id << endl;

}

const Date Task::getDate() const
{
	return this->date;
}

void Task::write(ofstream & stream)
{
	stream << this->title;
	stream << this->description;
	//Date i Time izvikvam ot classovete
	this->id++;
}

void Task::read(ifstream & stream)
{
	stream >> this->title;
	stream >> this->description;
	//Date i Time
}



Task::Task()
{
	this->title = new char[1];
	strcpy_s(this->title, 1, "");
	this->description = new char[1];
	strcpy_s(this->description, 1, "");
	this->type = Default;
	this->id++;
}

Task::Task(const char * title, const char * description, Time start, Time end, Types type, Date date)
{
	this->title = new char[strlen(title) + 1];
	strcpy_s(this->title, strlen(title) + 1, title);
	this->description = new char[strlen(description) + 1];
	strcpy_s(this->description, strlen(description) + 1, description);
	this->start = start;
	this->end = end;
	this->type = type;
	this->date = date;
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
	this->id--;
}

