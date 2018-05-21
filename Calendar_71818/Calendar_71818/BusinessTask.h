#pragma once
#include "Task.h"
#include "Person.h"
#include "LList.h"
#include "Time.h"
#include <cstring>

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
	}
	void destroy()
	{
		delete[] this->location;
	}
public:
	bool validDuration(Time start, Time end);
	void TaskDuration(Time start, Time end);
	const Time getDuration() const;
	void print();
	void write(ofstream& stream);
	void read(ifstream& stream);
	void initializeTask(int day, int month, int type);
	
	BusinessTask* clone() const;
	BusinessTask();
	BusinessTask(const char * title, const char * description, Time start, Time end, Types type, Date date, LList<Person> peopleAtMeeting, const char* location, Time duration, Person host);
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

void BusinessTask::print()
{
	Task::print();
	cout << "People at the meeting: " << endl;
	this->peopleAtMeeting.printData();
	cout << "Location of the meeting: " << this->location << endl;
	cout << "Duration of the meeting: ";
	this->duration.print();
	cout << "Name of host: ";
	this->host.print();
}

void BusinessTask::write(ofstream & stream)
{
	//v person za peopleAtMeeting
	stream << this->location;
	//vav Time za duration
	//vav person za host
}

void BusinessTask::read(ifstream & stream)
{
	//v person za peopleAtMeeting
	stream >> this->location;
	//vav Time za duration
	//vav person za host
}

void BusinessTask::initializeTask(int day, int month, int type)
{
	//Input za Date
	Date date(day, month, 2018);
	std::cout << "The date of the task is: ";
	date.print();
	
	//title
	std::cout << "Enter title of the task: " << std::endl;
	cin.getline(this->title, strlen(this->title));
	//description
	std::cout << "Give a description to your task: " << std::endl;
	cin.getline(this->description, strlen(this->description));
	//start
	std::cout << "What time does the event start? " << std::endl;
	int tempHours = 0, tempMinutes = 0;
	std::cin >> tempHours;
	this->start.setHours(tempHours);
	std::cin >> tempMinutes;
	this->start.setMinutes(tempMinutes);
	//end
	std::cout << "What time does the event end? " << std::endl;
	cin >> tempHours;
	this->end.setHours(tempHours);
	cin >> tempMinutes;
	this->end.setMinutes(tempMinutes);
	if (tempMinutes>59 && tempHours>23 && tempMinutes<0 && tempHours<0)
	{
		std::cout << "Invalid Time input! " << std::endl;
	}
	
	
	std::cout << "How many people are gonna be at the event? " << std::endl;
	int numberOfPeople;
	cin >> numberOfPeople;
	if (numberOfPeople<=0)
	{
		std::cout << "Wrong input!" << std::endl;
	}
	for (int i = 0; i < numberOfPeople; i++)
	{
		Person temp;
		std::cout << "Enter the first name: " << std::endl;
		char* name = new char;
		cin.getline(name, strlen(name) + 1);
		temp.setFirstName(name);
		cin.getline(name, strlen(name) + 1);
		temp.setLastName(name);
		this->peopleAtMeeting.push_back(temp);
	}
	std::cout << "What is the location of the event?" << std::endl;
	cin.getline(this->location, strlen(this->location));
	std::cout << "Host? " << std::endl;
	Person tempoooraryy;
	std::cout << "Enter the first name: " << std::endl;
	char* name = new char;
	cin.getline(name, strlen(name) + 1);
	tempoooraryy.setFirstName(name);
	cin.getline(name, strlen(name) + 1);
	tempoooraryy.setLastName(name);
	this->peopleAtMeeting.push_back(tempoooraryy);
}


BusinessTask * BusinessTask::clone() const
{
	return new BusinessTask(*this);
}

//the big four
BusinessTask::BusinessTask() :Task()
{
	this->location = new char[1];
	strcpy_s(this->location, 1, "");
}

BusinessTask::BusinessTask(const char * title, const char * description, Time start, Time end, Types type, Date date, LList<Person> peopleAtMeeting, const char * location, Time duration, Person host)
	:Task(title, description, start, end, type=Business,date)
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
