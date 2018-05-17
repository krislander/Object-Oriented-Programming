#pragma once
#include "Task.h"
#include "Person.h"
#include "Vector.h"
#include "Time.h"

class BusinessTask :public Task
{
private:
	Vector<Person> peopleAtMeeting;
	char* location;
	Time duration;
	Person host;

	void copy(const BusinessTask& other)
	{
		this->location = new char[strlen(other.location) + 1];
		strcpy_s(this->location, strlen(other.location) + 1, other.location);		
		this->duration = other.duration;
		this->host = other.host;
	}
	void destroy()
	{
		delete[] this->location;
	}
public:
	bool IsValidTime(int hours, int minutes);

	BusinessTask();
	BusinessTask(const char* title, const char* description, Time start, Time end, Vector<Person> peopleAtMeeting, const char* location, Time duration, Person host);
};

BusinessTask::BusinessTask() :Task()
{
	this->location = new char[1];
	strcpy_s(this->location, 1, "");
	Person _host;
	this->host = _host;
}

BusinessTask::BusinessTask(const char * title, const char * description, Time start, Time end, Vector<Person> peopleAtMeeting, const char * location, Time duration, Person host)
	:Task(title, description, start, end)
{
}
