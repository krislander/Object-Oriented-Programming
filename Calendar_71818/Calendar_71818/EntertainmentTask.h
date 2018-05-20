#pragma once
#include "Task.h"

class EntertainmentTask :public Task
{
public:
	enum TypesOfEntertainment
	{
		Default,
		BurningChurches,
		Drinking,
		Weed
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
	void addTask(Task& task);


	EntertainmentTask();
	EntertainmentTask(const EntertainmentTask& other);
	EntertainmentTask(const char* title, const char* description, Time start, Time end, Types type, Date date, TypesOfEntertainment typeOfFun, const char* location);
	~EntertainmentTask();
	//dobavqne na print
};

void EntertainmentTask::print()
{
	Task::print();
	cout << "Type of entertainment" << this->typeOfFun << endl;
	cout << "Location: " << this->location << endl;
}

void EntertainmentTask::addTask(Task & task)
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
	std::cout << "What is the type of Entertainment? " << std::endl;
	int type;
	cin >> type;
	TypesOfEntertainment userInput = type;
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
