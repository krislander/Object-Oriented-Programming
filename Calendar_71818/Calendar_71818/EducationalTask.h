#pragma once
#include "Task.h"

class EducationalTask : public Task
{
private:
	char* subjectName;
	char* stuffToDo;

	void copy(const EducationalTask& other)
	{
			this->subjectName = new char[strlen(other.subjectName) + 1];
			strcpy_s(this->subjectName, strlen(other.subjectName) + 1, other.subjectName);
			this->stuffToDo = new char[strlen(other.stuffToDo) + 1];
			strcpy_s(this->stuffToDo, strlen(other.stuffToDo) + 1, other.stuffToDo);
	}
	void destroy()
	{
		delete[] this->subjectName;
		delete[] this->stuffToDo;
	}

public:
	void print();

	EducationalTask();
	EducationalTask(const char* title, const char* description, Time start, Time end, Types type, Date date, const char* subjectName, const char* stuffToDo);
	EducationalTask(const EducationalTask& other);
	EducationalTask& operator=(const EducationalTask& other);
	~EducationalTask();
};

void EducationalTask::print()
{
	Task::print();
	cout << "Subject of study: " << this->subjectName << endl;
	cout << "Material to study: " << this->stuffToDo << endl;
}

EducationalTask::EducationalTask() : Task()
{
	this->subjectName = new char[1];
	strcpy_s(this->subjectName, 1, "");
	this->stuffToDo = new char[1];
	strcpy_s(this->stuffToDo, 1, "");
}

EducationalTask::EducationalTask(const char* title, const char* description, Time start, Time end, Types type, Date date, const char* subjectName, const char* stuffToDo)
	:Task(title, description, start, end, type,date)
{
	this->subjectName = new char[strlen(subjectName) + 1];
	strcpy_s(this->subjectName, strlen(subjectName) + 1, subjectName);
	this->stuffToDo = new char[strlen(stuffToDo) + 1];
	strcpy_s(this->stuffToDo, strlen(stuffToDo) + 1, stuffToDo);
}

EducationalTask::EducationalTask(const EducationalTask& other) : Task(other)
{
	this->copy(other);
}

EducationalTask& EducationalTask::operator=(const EducationalTask & other)
{
	if (this != &other)
	{
		Task::operator=(other);
		this->destroy();
		this->copy(other);
	}
	return *this;
}


EducationalTask::~EducationalTask()
{
	this->destroy();
}