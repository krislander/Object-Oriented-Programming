#pragma once
#include "Task.h"
#include "Person.h"
#include "LList.h"
#include "Time.h"

class BusinessTask :public Task
{
private:
	LList<Person> peopleAtMeeting;
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
	bool validDuration(Time start, Time end);
	void TaskDuration(Time start, Time end);
	const Time getDuration() const;

	BusinessTask();
	BusinessTask(const char * title, const char * description, Time start, Time end, Types type, LList<Person> peopleAtMeeting, const char* location, Time duration, Person host);
	BusinessTask(const BusinessTask& other);
	~BusinessTask();
};

bool BusinessTask::validDuration(Time start, Time end)
{
	if (start.getHours() <= end.getHours() && start.IsValidTime(start.getHours(), start.getMinutes()) && end.IsValidTime(end.getHours(), end.getMinutes()))
	{
		if (start.getMinutes() < end.getMinutes())
		{
			return true;
		}
	}
	return false;
}

void BusinessTask::TaskDuration(Time start, Time end)
{
	if (validDuration(start, end))
	{
		duration = end - start;
	}
}

const Time BusinessTask::getDuration() const
{
	return this->duration;
}

BusinessTask::BusinessTask() :Task()
{
	this->location = new char[1];
	strcpy_s(this->location, 1, "");
}

BusinessTask::BusinessTask(const char * title, const char * description, Time start, Time end, Types type, LList<Person> peopleAtMeeting, const char * location, Time duration, Person host)
	:Task(title, description, start, end, type)
{
	this->peopleAtMeeting = peopleAtMeeting;
	this->location = new char[strlen(location) + 1];
	strcpy_s(this->location, strlen(location) + 1, location);
	this->duration = duration;
	this->host = host;
}

BusinessTask::BusinessTask(const BusinessTask & other):Task(other)
{
	this->copy(other);
}

BusinessTask::~BusinessTask()
{
	this->destroy();
}
