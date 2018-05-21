#pragma once
#include "Task.h"

class EntertainmentTask :public Task
{
public:
	enum TypesOfEntertainment
	{
		Default,
		Movies,
		Drinking,
		Swimming,
	};
private:
	TypesOfEntertainment typeOfFun;
	char* location;
	// da se proverq meteoroligichnoto vreme na tazi lokaciq system("start chrome  https://www.sinoptik.bg/search?q={карлово}");)
	//sashto taka trqbva da proverq dali tozi location e validen

	void copy(const EntertainmentTask& other)
	{
		this->typeOfFun = other.typeOfFun;
		this->location = new char[strlen(other.location) + 1];
		strcpy_s(this->location, strlen(other.location) + 1, other.location);
		//tuka ima dobavki za weatherCheck
	}
	void destroy()
	{
		Task::~Task();
		delete[] this->location;
	}
public:
	void print();
	void initializeTask(int day, int month, int type);

	EntertainmentTask* clone() const;
	EntertainmentTask();
	EntertainmentTask(const EntertainmentTask& other);
	EntertainmentTask(const char* title, const char* description, Time start, Time end, Types type, Date date, TypesOfEntertainment typeOfFun, const char* location);
	~EntertainmentTask();
};

void EntertainmentTask::print()
{
	Task::print();
	cout << "Type of entertainment" << this->typeOfFun << endl;
	cout << "Location: " << this->location << endl;
}

void EntertainmentTask::initializeTask(int day, int month, int type)
{
	std::cout << "Enter title of the task: " << std::endl;
	cin.getline(this->title, strlen(this->title));
	std::cout << "Give a description to your task: " << std::endl;
	cin.getline(this->description, strlen(this->description));
	std::cout << "What time does the event start? " << std::endl;
	int tempHours = 0, tempMinutes = 0;
	std::cin >> tempHours;
	this->start.setHours(tempHours);
	std::cin >> tempMinutes;
	this->start.setMinutes(tempMinutes);
	std::cout << "What time does the event end? " << std::endl;
	std::cin >> tempHours;
	this->end.setHours(tempHours);
	std::cin >> tempMinutes;
	this->end.setMinutes(tempMinutes);
	if (tempMinutes>59 && tempHours>23 && tempMinutes<0 && tempHours<0)
	{
		std::cout << "Invalid Time input! " << std::endl;
	}
	//types of entertainment
	std::cout << "What is the type of Entertainment? " << std::endl;
	int typeEntertainment;
	cin >> typeEntertainment;
	TypesOfEntertainment userInput;
	if (typeEntertainment == 1)
		userInput = Movies;
	if (typeEntertainment == 2)
		userInput = Drinking;
	if (typeEntertainment == 3)
		userInput = Swimming;
	else
		std::cout << "Invalid input! " << std::endl;
	//location
	std::cout << "Where is the location? " << std::endl;
	cin.getline(this->location, strlen(this->location));
	//weathercheck???
}

EntertainmentTask * EntertainmentTask::clone() const
{
	return new EntertainmentTask(*this);
}

EntertainmentTask::EntertainmentTask() :Task()
{
	this->typeOfFun = Default;
	this->location = new char[1];
	strcpy_s(this->location, 1, "");
}
EntertainmentTask::EntertainmentTask(const EntertainmentTask & other) :Task(other)
{
	this->copy(other);
}
EntertainmentTask::EntertainmentTask(const char* title, const char* description, Time start, Time end, Types type, Date date, TypesOfEntertainment typeOfFun, const char* location)
	: Task(title, description, start, end, type = Entertainment,date)
{
	this->location = new char[strlen(location) + 1];
	strcpy_s(this->location, strlen(location) + 1, location);
}

EntertainmentTask::~EntertainmentTask()
{
	this->destroy();
}
