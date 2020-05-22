#include <iostream>
#include "DeckOfCards.h"
#include "Player.h"
#include "Game.h"

using namespace std;

//Изтегляне на случайна карта
void Game::drawNextCard()
{
	Card nextcard = deck.draw();
	cout << nextcard << endl;
}

//Започване на играта с Default Deck
void Game::startNewGameWithDefaultDeck()
{
	this->deck = DeckOfCards();
	deck.generateDefaultDeck();
}

//Започване на играта с Custom Deck
void Game::startNewGameWithCustomDeck(int k, const char* seria)
{
	this->deck = DeckOfCards();
	deck.generateCustomDeck(k, seria);
}
