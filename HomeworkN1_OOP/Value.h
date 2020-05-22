#pragma once
#include <iostream>
#include "Common.h"

class Value 
{
private:
	char* nameOfSymbol;
	int points;
	void erase();
	void copy(const Value& other);

public:
	Value();
	Value(const char* name);
	Value(const char* name, int points);
	Value(const Value& other);
	Value& operator=(const Value& other);
	bool operator==(const Value& other);
	int getPoints() const;
	char* getNameOfSymbol() const;
	friend ostream& operator<<(ostream& os, const Value& v);

private:
	int getPointsByNameOfSymbol(const char* name);
};


