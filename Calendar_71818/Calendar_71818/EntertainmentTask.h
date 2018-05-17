#pragma once
#include "Task.h"

class EntertainmentTask :public Task
{
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
	enum TypesOfEntertainment
	{
		BurningChurches,
		Drinking,
		Weed
	};

	EntertainmentTask();
	EntertainmentTask(const EntertainmentTask& other);
	EntertainmentTask(const char* title, const char* description, Time start, Time end, Types type, Date date, TypesOfEntertainment typeOfFun, const char* location);
	~EntertainmentTask();
	//dobavqne na print
};

EntertainmentTask::EntertainmentTask() :Task()
{
	this->typeOfFun = BurningChurches;
	this->location = new char[1];
	strcpy_s(this->location, 1, "");
}
EntertainmentTask::EntertainmentTask(const EntertainmentTask & other) :Task(other)
{
	this->copy(other);
}
EntertainmentTask::EntertainmentTask(const char* title, const char* description, Time start, Time end, Types type, Date date, TypesOfEntertainment typeOfFun, const char* location)
	: Task(title, description, start, end, type,date)
{
	this->location = new char[strlen(location) + 1];
	strcpy_s(this->location, strlen(location) + 1, location);
}

EntertainmentTask::~EntertainmentTask()
{
	this->destroy();
}
