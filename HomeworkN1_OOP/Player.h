#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include "Common.h"

using namespace std;

class Player
{
private:
	char* name;
	int years;
	size_t wins;
	size_t playedGames;
	size_t currentPoints;
	void copy(const Player& other);
	void erase();
	
public:
	Player();
	Player(const char* name, int years);
	Player(const Player& other);
	Player& operator=(const Player& other);
	bool operator==(const Player& other);
	double coefficientOfWins();
	~Player();
	
	//Setters
	void setName(const char* name);
	void setYears(const int years);
	void setWins(const size_t wins);
	void setPlayedGames(const size_t playedGames);
	//void setCoefficientOfWins(const double coefficientOfWins);
	void setCurrentPoints(const size_t currentPoints);
	
	//Getters
	char* getName()const;
	int getYears()const;
	size_t getWins()const;
	size_t getPlayedGames()const;
	//double getCoefficientOfWins()const;
	size_t getCurrentPoints()const;

	friend ostream& operator<<(ostream& os, const Player& p);
};