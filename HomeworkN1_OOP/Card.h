#pragma once
#include <iostream>
#include "Paint.h"
#include "Value.h"
#include "Common.h"

using namespace std;

class Card
{
private:
	Paint paint;
	Value value;
	char* serialNumber;
	void copy(const Card& other);
	void erase();


public:
	Card();
	Card(Paint paint, Value value, const char* serialNumber);
	Card(Value cardValue, Paint cardPaint);
	Card(const Card& other);
	Card& operator=(const Card& other);
	~Card();

	//Setters
	void setSerialNumber(const char* serialNumber);
	void setPaint(const Paint paint);
	void setValue(const Value value);

	//Getters
	char getSerialNumber()const;
	Paint getPaint()const;
	Value getValue() const;

	friend ostream& operator<<(ostream& os, const Card& c);
};