#include <iostream>
#include <vector>
#include <string>
#include "DeckOfCards.h"
#include <assert.h>

using namespace std;

void DeckOfCards::copy(const DeckOfCards& other)
{
	this->cardsCount = other.cardsCount;
	this->undrawnCardsCount = other.undrawnCardsCount;
	this->cards = new Card[MAX_DECK_SIZE];

	for (int i = 0; i < other.cardsCount; i++)
	{
		this->cards[i] = other.cards[i];
	}

	if(other.seria != nullptr)
	{
		assert(strlen(other.seria) <= MAX_SERIA_LENGTH);
	}

	this->seria = nullptr;
	mystrcpy(this->seria, other.seria);
}

void DeckOfCards::erase()
{
	delete[] this->seria;
}

//Конструктор по подразбиране
DeckOfCards::DeckOfCards()
{
	this->cards = nullptr;
	this->cardsCount = 0;
	this->undrawnCardsCount = 0;
	this->seria = nullptr;
}

//Конструктор с параметри
DeckOfCards::DeckOfCards(Card cards[], int cardsCount, char* seria)
{
	this->cards = cards;
	this->cardsCount = cardsCount;
	this->undrawnCardsCount = cardsCount;
	assert(strlen(seria) <= MAX_SERIA_LENGTH);
	this->seria = nullptr;
	mystrcpy(this->seria, seria);
	populateSerialNumbers();
}

//Copy конструктор
DeckOfCards::DeckOfCards(const DeckOfCards& other)
{
	this->copy(other);
}

//Оператор =
DeckOfCards& DeckOfCards::operator=(const DeckOfCards& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}
	return *this;
}

//Деструктор
DeckOfCards::~DeckOfCards()
{
	this->erase();
}

//Setters
void DeckOfCards::setCards(const Card* cards)
{
	*this->cards = *cards;
}

void DeckOfCards::setCardsCount(const int cardsCount)
{
	this->cardsCount = cardsCount;
}

void DeckOfCards::setSeria(const char* seria)
{
	assert(strlen(seria) <= MAX_SERIA_LENGTH);
	this->seria = nullptr;
	mystrcpy(this->seria, seria);
}

//Getters
Card* DeckOfCards::getCards()const
{
	return this->cards;
}

int DeckOfCards::getCardsCount() const
{
	return this->cardsCount;
}

char* DeckOfCards::getSeria() const
{
	return this->seria;
}

int DeckOfCards::digitsCounter(int number)
{
	int count = 0;
	while (number != 0)
	{
		number = number / 10;
		count++;
	}
	return count;
}

//Функция, която добавя серийни номера на картите.
void DeckOfCards::populateSerialNumbers() {
	for (int i = 0; i < this->cardsCount; i++)
	{
		char* deckSeria = nullptr;
		mystrcpy(deckSeria, this->seria);
		const int digitsCount = digitsCounter(cardsCount);
		char* buffer = new char[digitsCount];
		itoa(i, buffer, 10);
		this->cards[i].setSerialNumber(strcat(deckSeria, buffer));
	}
}

//Оператор <<
ostream& operator<<(ostream& os, const DeckOfCards& deck)
{
	os << "Seria: " << deck.getSeria() << endl;
	for (int i = 0; i < deck.cardsCount; i++)
	{
		os << deck.cards[i] << endl;
	}

	return os;
}

//Операция swap 
void DeckOfCards::swap(int i, int j)
{
	swapCardsInArray(i, j, this->cards, this->cardsCount);
}

//Операция swap в масиви
void DeckOfCards::swapCardsInArray(int i, int j, Card* cards, int cardsCount)
{
	if (i < cardsCount && j < cardsCount && i >= 0 && j >= 0)
	{
		Card temp = cards[i];
		cards[i] = cards[j];
		cards[j] = temp;
	}
}

//Операция draw
Card DeckOfCards::draw()
{
	Card temp = this->cards[0];
	for (int i = 0; i < cardsCount - 1; i++)
	{
		cards[i] = cards[i + 1];
	}

	cards[cardsCount - 1] = temp;
	undrawnCardsCount--;

	return temp;
}

//Операция suit_count
int DeckOfCards::suit_count(Paint p)
{
	int count = 0;
	for (int i = 0; i < cardsCount; i++)
	{
		if (this->cards[i].getPaint() == p)
		{
			count++;
		}
	}

	return count;
}

//Операция rank_count
int DeckOfCards::rank_count(Value v)
{
	int count = 0;
	for (int i = 0; i < undrawnCardsCount; i++)
	{
		if (this->cards[i].getValue() == v)
		{
			count++;
		}
	}

	return count;
}

//Генериране на default deck
void DeckOfCards::generateDefaultDeck() 
{
	this->cardsCount = MAX_DECK_SIZE;
	this->cards = new Card[MAX_DECK_SIZE];
	this->seria = nullptr;
	mystrcpy(this->seria, "Default");

	generateDeck(this->cards);
	populateSerialNumbers();
	shuffle();
}

//Разбъркване на картите
void DeckOfCards::shuffle() 
{
	for (int i = 0; i < cardsCount; i++)
	{
		int firstIndex = generateRandomNumber(0, cardsCount - 1);
		int secondIndex = generateRandomNumber(0, cardsCount - 1);
		swap(firstIndex, secondIndex);
	}
}

//Разбъркване на карти в масив
void DeckOfCards::shuffleCardsInArray(Card* cards, int cardsCount)
{
	for (int i = 0; i < cardsCount; i++)
	{
		int firstIndex = generateRandomNumber(0, cardsCount - 1);
		int secondIndex = generateRandomNumber(0, cardsCount - 1);
		swapCardsInArray(firstIndex, secondIndex, cards, cardsCount);
	}
}

//Генератор на случайни числа
//Използвано от https://stackoverflow.com/questions/19665818/generate-random-numbers-using-c11-random-library
int DeckOfCards::generateRandomNumber(int from, int to)
{
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<double> dist(from, to);
	return dist(mt);
}

//Генериране на custom deck
void DeckOfCards::generateCustomDeck(int k, const char* seria)
{
	this->cardsCount = k;
	this->cards = new Card[k];
	this->seria = nullptr;

	if (seria == nullptr)
	{
		mystrcpy(this->seria, "Custom");
	}

	else
	{
		mystrcpy(this->seria, seria);
	}
	Card* tempDeck = new Card[MAX_DECK_SIZE];
	generateDeck(tempDeck);
	
	int fullDecksCount = k / MAX_DECK_SIZE;
	int remainingCardsCount = k % MAX_DECK_SIZE;
	int cardsIndex = 0;
	for (int i = 0; i < fullDecksCount; i++)
	{
		shuffleCardsInArray(tempDeck, MAX_DECK_SIZE);
		for (int j = 0; j < MAX_DECK_SIZE; j++)
		{
			this->cards[cardsIndex] = Card(tempDeck[j]);
			cardsIndex++;
		}
	}

	shuffleCardsInArray(tempDeck, MAX_DECK_SIZE);
	for (int i = 0; i < remainingCardsCount; i++)
	{
		this->cards[cardsIndex] = Card(tempDeck[i]);
		cardsIndex++;
	}
	populateSerialNumbers();
	shuffle();
}

//Генериране на тесте
void DeckOfCards::generateDeck(Card* cards)
{
	int cardsIndex = 0;
	for (int paintIndex = Paint::Spade; paintIndex <= Paint::Heart; paintIndex++)
	{
		Paint paint = static_cast<Paint>(paintIndex);
		for (int valueIndex = 0; valueIndex < VALUES_SIZE; valueIndex++)
		{
			const char* nameOfSymbolFromValues = values[valueIndex].first;
			Value v = Value(nameOfSymbolFromValues);
			cards[cardsIndex] = Card(v, paint);
			cardsIndex++;
		}
	}
}


