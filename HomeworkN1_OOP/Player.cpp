#include <iostream>
#include "Player.h"

using namespace std;

void Player::copy(const Player& other)
{
	this->name = nullptr;
	mystrcpy(this->name, other.name);
	this->years = other.years;
	this->wins = other.wins; 
	this->playedGames = other.playedGames;
	this->currentPoints = other.currentPoints;
}

void Player::erase()
{
	delete[] this->name;
}

//Конструктор по подразбиране
Player::Player()
{
	this->name = nullptr;
	this->years = 0;
	this->wins = 0;
	this->playedGames = 0;
	this->currentPoints = 0;
}

//Конструктор с параметри
Player::Player(const char* name, int years)
{
	this->name = nullptr;
	mystrcpy(this->name, name);
	this->years = years;
	this->wins = 0;
	this->playedGames = 0;
	this->currentPoints = 0;
}

//Copy конструктор
Player::Player(const Player& other)
{
	this->copy(other);
	this->years = other.years;
	this->wins = other.wins;
	this->playedGames = other.playedGames;
	this->currentPoints = other.currentPoints;
}

//Оператор =
Player& Player::operator=(const Player& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}

	return *this;
}

//Оператор ==
bool Player::operator==(const Player& other)
{
	return this->years == other.years &&
		this->wins == other.wins &&
		this->playedGames == other.playedGames &&
		this->currentPoints == other.currentPoints &&
		strcmp(this->name, other.name) == 0;
}

double Player::coefficientOfWins()
{
	if (this->playedGames == 0)
	{
		return 0;
	}

	else
		return this->wins / this->playedGames;
}

//Деструктор
Player::~Player()
{
	this->erase();
}

//Setters
void Player::setName(const char* name)
{
	this->erase();
	this->name = nullptr;
	mystrcpy(this->name, name);
}

void Player::setYears(const int years)
{
	this->years = years;
}

void Player::setWins(const size_t wins)
{
	this->wins = wins;
}

void Player::setPlayedGames(const size_t playedGames)
{
	this->playedGames = playedGames;

}

void Player::setCurrentPoints(const size_t currentPoints)
{
	this->currentPoints = currentPoints;
}

//Getters
char* Player::getName()const
{
	return this->name;
}

int Player::getYears()const
{
	return this->years;
}

size_t Player::getWins()const
{
	return this->wins;
}

size_t Player::getPlayedGames()const
{
	return this->playedGames;
}

size_t Player:: getCurrentPoints()const
{
	return this->currentPoints;
}

//Оператор <<
ostream& operator<<(ostream& os, const Player& p)
{
	if (p.name != nullptr) 
	{
		os << "Name: " << p.getName() << endl;
	}

	os << "Years: " << p.getYears() << endl;
	os << "Wins: " << p.getWins() << endl;
	os << "Played games: " << p.getPlayedGames() << endl;
	os << "Current points: " << p.getCurrentPoints() << endl;
	
	return os;
}



