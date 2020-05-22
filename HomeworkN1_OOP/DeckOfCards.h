#pragma once
#include <iostream>
#include "Card.h"
#include "Common.h"
#include <stdio.h>
#include <stdlib.h>
#include <random>

class DeckOfCards
{
private:
	Card* cards;
	int cardsCount;
	char* seria;
	int undrawnCardsCount;
	void copy(const DeckOfCards& other);
	void erase();
	void populateSerialNumbers();
	int generateRandomNumber(int from, int to);
	void shuffle();
	void shuffleCardsInArray(Card* cards, int cardsCount);
	void swapCardsInArray(int i, int j, Card* cards, int cardsCount);
	int digitsCounter(int number);

public:
	DeckOfCards();
	DeckOfCards(Card cards[], int cardsCount, char* seria);
	DeckOfCards(const DeckOfCards& other);
	DeckOfCards& operator=(const DeckOfCards& other);
	~DeckOfCards();

	//Setters
	void setCards(const Card* cards);
	void setCardsCount(const int cardsCount);
	void setSeria(const char* seria);

	//Getters
	Card* getCards()const;
	int getCardsCount() const;
	char* getSeria() const;

	friend ostream& operator<<(ostream& os, const DeckOfCards& deck);

	void swap(int i, int j);
	Card draw();
	int suit_count(Paint p);
	int rank_count(Value v);
	void generateDefaultDeck();
	void generateCustomDeck(int k, const char* seria);
	void generateDeck(Card* cards);
	void generateRandomCard();
};
