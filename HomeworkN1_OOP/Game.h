#pragma once
#include <iostream>
using namespace std;

class Game
{
public:
	DeckOfCards deck;
	void startNewGameWithDefaultDeck();
	void startNewGameWithCustomDeck(int k, const char* seria);
	void drawNextCard();
};