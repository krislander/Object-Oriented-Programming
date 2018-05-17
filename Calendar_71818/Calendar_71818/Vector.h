#pragma once
#include <iostream>
#include <cstring>

using namespace std;

template <class T>
class Vector
{
private:
	T * value;
	size_t count;//drugiqt variant za broqchite na dinamichen masiv e unsigned int
	size_t capacity;

	void copy(const Vector& other);
	void erase();
	void resize();
public:
	Vector();
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	~Vector();
	void push_back(T element);
	void push(T element, size_t index);
	void pop_back();
	void pop_front();
	void pop(size_t index);
	T operator[](size_t index) const;
	int operator[](T element) const;
	void print() const;
};

template<class T>
void Vector<T>::copy(const Vector<T> & other)
{
	this->value = new T[other.capacity];
	for (size_t i = 0; i < other.count; i++)
	{
		this->value[i] = other.value[i];
	}
	this->count = other.count;
	this->capacity = other.capacity;
}

template<class T>
void Vector<T>::erase()
{
	delete[] this->value;
}

template<class T>
void Vector<T>::resize()
{
	this->capacity = 2 * this->capacity + 1;
	T* temp = new T[this->capacity];
	for (size_t i = 0; i < this->count; i++)
	{
		temp[i] = this->value[i];
	}
	this->erase();

	value = temp;
}

template<class T>
Vector<T>::Vector()
{
	this->capacity = 8;
	this->count = 0;
	this->value = new T[this->capacity];
}

template<class T>
Vector<T>::Vector(const Vector & other)
{
	this->copy(other);
}

template<class T>
Vector<T> & Vector<T>::operator=(const Vector & other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}
	return *this;
}

template<class T>
Vector<T>::~Vector()
{
	this->erase();
}

template<class T>
void Vector<T>::push_back(T element)
{
	if (this->count >= this->capacity)
	{
		this->resize();
	}
	this->value[this->count++] = element;
}

template<class T>
void Vector<T>::push(T element, size_t index)//10, 3ta poziciq
{
	this->count++;//11

	for (int i = this->count; i > index + 1; i--)//ot 11 do 4 taka osvobojdavame 3ti
	{
		this->value[i] = this->value[i - 1];
	}
	this->value[index] = element;
}

template<class T>
void Vector<T>::pop_back()
{
	this->count--;
}

template<class T>
void Vector<T>::pop_front()
{
	T temp = this->value[1];
	for (size_t i = 0; i < this->count - 1; i++)
	{
		this->value[i] = temp;
		temp = this->value[i + 1];
	}
	this->count--;
}

template<class T>
void Vector<T>::pop(size_t index)
{

}

template<class T>
T Vector<T>::operator[](size_t index) const
{
	return this->value[index];
}

template<class T>
int Vector<T>::operator[](T element) const
{
	for (int i = 0; i < this->count; i++)
	{
		if (element == this->value[i])
		{
			return i;
		}
	}
	return -1;
}

template<class T>
void Vector<T>::print() const
{
	for (int i = 0; i < this->count; i++)
	{
		cout << this->value[i] << endl;
	}
}


