#pragma once
#include <iostream>


class Person
{
private:
	char* firstName;
	char* lastName;

	void copy(const Person& other)
	{	
			this->firstName = new char[strlen(other.firstName) + 1];
			strcpy_s(this->firstName, strlen(other.firstName) + 1, other.firstName);
			this->lastName = new char[strlen(other.lastName) + 1];
			strcpy_s(this->lastName, strlen(other.lastName) + 1, other.lastName);
	}
	void destroy()
	{
		delete[] this->firstName;
		delete[] this->lastName;
	}
public:
	Person();
	Person(const char* firstName, const char* lastName);
	Person(const Person& other);
	~Person();
};

Person::Person()
{
	this->firstName = new char[1];
	strcpy_s(this->firstName, 1, "");
	this->lastName = new char[1];
	strcpy_s(this->lastName, 1, "");
}

Person::Person(const char * firstName, const char * lastName)
{
	this->firstName = new char[strlen(firstName) + 1];
	strcpy_s(this->firstName, strlen(firstName) + 1, firstName);
	this->lastName = new char[strlen(lastName) + 1];
	strcpy_s(this->lastName, strlen(lastName) + 1, lastName);
}

Person::Person(const Person & other)
{
	this->copy(other);
}

Person::~Person()
{
	this->destroy();
}