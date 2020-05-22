#pragma once
#include <iostream>

using namespace std;

class Dealer
{
private:
	size_t currentPoints;
	void copy(const Dealer& other);

public:
	Dealer();
	Dealer(const size_t currentPoints);
	Dealer(const Dealer& other);
	Dealer& operator=(const Dealer& other);
	bool operator==(const Dealer& other);

	//Setters
	void setCurrentPoints(const size_t currentPoints);

	//Getters
	size_t getCurrentPoints()const;

	friend ostream& operator<<(ostream& os, const Dealer& d);
};
