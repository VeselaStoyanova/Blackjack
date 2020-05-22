#include <iostream>
#include "Dealer.h"

using namespace std;

void Dealer::copy(const Dealer& other)
{
	this->currentPoints = other.currentPoints;
}

//Конструктор по подразбиранe
Dealer::Dealer()
{
	this->currentPoints = 0;
}

//Конструктор с параметри
Dealer::Dealer(const size_t currentPoints)
{
	this->currentPoints = currentPoints;
}

//Copy конструктор
Dealer::Dealer(const Dealer& other)
{
	this->currentPoints = other.currentPoints;
}

//Оператор =
Dealer& Dealer::operator=(const Dealer& other)
{
	if (this != &other)
	{
		this->copy(other);
	}

	return *this;
}

//Оператор ==
bool Dealer::operator==(const Dealer& other)
{
	return 
	this->currentPoints == other.currentPoints == 0;
}

//Setter
void Dealer::setCurrentPoints(const size_t currentPoints)
{
	this->currentPoints = currentPoints;
}

//Getter
size_t Dealer::getCurrentPoints()const
{
	return this->currentPoints;
}

//Оператор <<
ostream& operator<<(ostream& os, const Dealer& d)
{
	os << "Current points: " << d.getCurrentPoints() << endl;
	return os;
}