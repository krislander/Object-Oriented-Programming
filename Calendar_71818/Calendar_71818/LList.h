#pragma once
#include "stdafx.h"
#include <iostream>
using namespace std;

template <class T>
struct Node
{
	T data;
	Node<T>* next;

	Node(const T& data, Node<T>* next)
	{
		this->data = data;
		this->next = next;
	}
};

template <class T>
class LList
{
private:
	Node<T>* first;
	Node<T>* last;
	size_t size;


	void copy(const LList& other)
	{
		Node<T>* temp = other.first;
		for (size_t i = 0; i < other.getNumberOfElements(); i++)
		{
			push_back(temp->data);
			temp = temp->next;
		}
	}
	void destroy()
	{
		while (size>0)
		{
			this->pop_front();
		}
	}
public:
	LList();
	~LList();
	LList(const LList& other);
	LList& operator=(const LList<T>& other);
	void pop_front();
	void push_back(const T& data);
	bool isEmpty() const;
	int getNumberOfElements() const;
	void push_front(const T& data);
	void pop_back();
	void push(const T& data, int index);
	Node<T>* get_ith(int index);
	void init();
	void remove(int index);
	void changeValAtIndex(const T& data, int index);
	void removeAllocc(const T& elem);
	void reverse();
	void printData() const;
	LList& operator + (const LList<T>& other);
	LList& operator += (const LList<T>& other);
};


template<class T>
LList<T> ::LList()
{
	this->first = nullptr;
	this->last = nullptr;
	this->size = 0;
}

template<class T>
LList<T>::~LList()
{
	this->destroy();
}

template<class T>
LList<T>::LList(const LList& other)
{
	copy(other);
}

template<class T>
LList<T>& LList<T>:: operator=(const LList<T>& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}

	return *this;
}

template<class T>
void LList<T>::pop_front()
{
	Node<T>* temp = first;
	this->first = first->next;
	delete temp;
	size--;
}

template<class T>
void LList<T>::push_back(const T& data)
{
	Node<T>* temp = new Node<T>(data, nullptr);
	if (temp)
	{
		if (this->size == 0)
		{
			this->first = temp;
			this->last = temp;
		}
		else
		{
			this->last->next = temp;
			this->last = temp;
		}
		size++;
	}
}

template<class T>
bool LList<T>::isEmpty() const
{
	if (this->size == 0)
	{
		return true;
	}
	else return false;
}

template<class T>
int LList<T> ::getNumberOfElements() const
{
	return this->size;
}

template<class T>
void LList<T>::push_front(const T & data)
{
	Node<T>* temp = new Node<T>(data, NULL);
	if (temp)
	{
		if (this->size == 0)
		{
			this->first = temp;
			this->last = temp;
		}
		else
		{
			temp->next = first;
			first = temp;
		}
	}
	size++;
}

template<class T>
void LList<T>::pop_back()
{
	Node<T>* temp = first;
	Node<T>* temp2 = last;
	while (temp->next != last)
	{
		temp = temp->next;
	}
	last = temp2;
	delete temp2;
	size--;
}

template<class T>
void LList<T>::push(const T& data, int index)
{
	if (!isEmpty()) {
		if (index < 0 || index > size) {
			cout << "NO";
		}
		else if (index == 0) {
			push_front(data);
		}
		else if (index == size - 1) {
			push_back(data);
		}
		else {

			Node<T> * newel = new Node<T>(data, NULL);
			Node<T> * temp = first;
			while (index != 1) {
				temp = temp->next;
				index--;
			}

			newel->next = temp->next;
			temp->next = newel;
			size++;
		}
	}
}

template<class T>
Node<T>* LList<T>::get_ith(int index)
{
	if (index<0 || index>this->size)
	{
		return NULL;
	}
	Node<T>* temp = first;
	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	return temp;
}

template<class T>
void LList<T>::init()
{
	this->first = nullptr;
	this->last = nullptr;
	this->size = 0;
}

template<class T>
void LList<T>::remove(int index)
{
	if (!isEmpty())
	{
		if (index<0 || index > size)
		{
			cout << "NO" << endl;
		}
		else if (index == 1)
		{
			pop_front();
		}
		else if (index == size - 1)
		{
			pop_back();
		}
		else
		{
			Node<T>* temp = first;
			while (index != 1)
			{
				temp = temp->next;
				index--;
			}

			Node<T>* save = temp->next;
			temp->next = temp->next->next;
			delete save;
			size--;
		}
	}
}

template<class T>
void LList<T>::changeValAtIndex(const T & data, int index)
{
	if (!isEmpty())
	{
		if (index<0 || index>size)
		{
			cout << "No" << endl;
		}
		else
		{
			get_ith(index)->data = data;
		}
	}
	else
	{
		cout << "List is empty" << endl;
	}
}

template<class T>
void LList<T>::removeAllocc(const T & elem)
{
	Node<T>* temp = first;
	Node<T>* prev = first;

	while (temp != NULL)
	{
		if (temp->data == elem)
		{
			if (temp == first)
			{
				first = temp->next;
				delete temp;
				temp = first;
				size--;
			}
			else
			{
				prev->next = temp->next;
				delete temp;
				temp = prev->next;
				size--;
			}
		}
		else
		{
			prev = temp;
			temp = temp->next;
		}
	}
}

template<class T>
void LList<T>::reverse()
{
	Node<T>* previous = NULL;
	Node<T>* curr = first;
	Node<T>* next = NULL;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = previous;
		previous = curr;
		curr = next;
	}
	first = previous;
}

template<class T>
void LList<T>::printData() const
{
	Node<T>* temp = this->first;

	for (int i = 0; i < this->size; i++)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}

template<class T>
LList<T> & LList<T>::operator+(const LList<T>& other)
{
	LList<T> * newl = new LList<T>(*this);
	Node<T> * temp = other.first;
	for (int i = 0; i < other.getNumberOfElements(); i++) {
		newl->push_back(temp->data);
		temp = temp->next;
	}
	return *newl;
}

template<class T>
LList<T> & LList<T>::operator+=(const LList<T>& other)
{
	Node<T> * temp = other.first;
	while (temp != NULL) {
		this->push_back(temp->data);
		temp = temp->next;

	}
	return *this;
}


