#include <iostream>
#include "Value.h"

//Конструктор по подразбиране
Value::Value() 
{
	this->nameOfSymbol = nullptr;
	this->points = 0;
}

void Value::erase()
{
	delete[] this->nameOfSymbol;
}

void Value::copy(const Value& other)
{
	this->nameOfSymbol = nullptr;
	mystrcpy(this->nameOfSymbol, other.nameOfSymbol);
	this->points = other.points;
}

Value::Value(const char* name)
{
	this->nameOfSymbol = nullptr;
	mystrcpy(this->nameOfSymbol, name);
	this->points = getPointsByNameOfSymbol(name);
}

//Конструктор с параметри
Value::Value(const char* name, int points)
{
	this->nameOfSymbol = nullptr;
	mystrcpy(this->nameOfSymbol, name);
	this->points = points;
}

//Copy конструктор
Value::Value(const Value& other)
{
	this->copy(other);
}

//Оператор =
Value& Value::operator=(const Value& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}

	return *this;
}

//Оператор ==
bool Value::operator==(const Value& other)
{
	return this->points == other.points &&
		strcmp(this->nameOfSymbol, other.nameOfSymbol) == 0;
}

//Getters
int Value::getPoints() const
{
	return points;
}

char* Value::getNameOfSymbol() const
{
	return this->nameOfSymbol;
}

//Функция, чрез която намираме колко точки носи карта.
int Value::getPointsByNameOfSymbol(const char* name)
{
	int value = 0;
	for (int i = 0; i < VALUES_SIZE; i++)
	{
		if (strcmp(values[i].first, name) == 0)
		{
			value = values[i].second;
		}
	}
	return value;
}

//Оператор <<
ostream& operator<<(ostream& os, const Value& v)
{
	os << v.getNameOfSymbol();
	return os;
}
