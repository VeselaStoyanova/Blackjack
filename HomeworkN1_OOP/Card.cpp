#include <iostream>
#include <vector>
#include <string>
#include "Card.h"

using namespace std;

void Card::copy(const Card& other)
{
	this->serialNumber = nullptr;
	mystrcpy(this->serialNumber, other.serialNumber);
	this->paint = other.paint;
	this->value = other.value;
}

void Card::erase()
{
	delete[] this->serialNumber;
}

//Конструктор по подразбиране
Card::Card()
{
	this->serialNumber = nullptr;
	this->value = Value();
	this->paint = Paint();
}

Card::Card(Value cardValue, Paint cardPaint)
{
	value = cardValue;
	paint = cardPaint;
	this->serialNumber = nullptr;
}

//Конструктор с параметри
Card::Card(Paint paint, Value value, const char* serialNumber)
{
	this->serialNumber = nullptr;
	mystrcpy(this->serialNumber, serialNumber);
	this->paint = paint;
	this->value = value;
}

//Copy конструктор
Card::Card(const Card& other)
{
	this->copy(other);
}

//Оператор =
Card& Card::operator=(const Card& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}

	return *this;
}

//Деструктор
Card::~Card()
{
	this->erase();
}


//Setters
void Card::setSerialNumber(const char* serialNumber)
{
	this->erase();
	this->serialNumber = nullptr;
	mystrcpy(this->serialNumber, serialNumber);
}

void Card::setPaint(const Paint paint)
{
	this->paint = paint;
}

void Card::setValue(const Value value)
{
	this->value = value;
}

//Getters
char Card::getSerialNumber()const
{
	return *this->serialNumber;
}

Paint Card::getPaint()const
{
	return this->paint;
}

Value Card::getValue() const
{
	return this->value;
}

ostream& operator<<(ostream& os, const Card& c)
{
	os << c.getValue() << " (" << c.getPaint() << ") ";
	os << "(Points: " << c.getValue().getPoints() << ") ";
	os << endl;
	return os;
}

