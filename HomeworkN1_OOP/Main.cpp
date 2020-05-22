#include <iostream>
#include <vector>
#include <string>
#include "Card.h"
#include "Dealer.h"
#include "DeckOfCards.h"
#include "Game.h"
#include "Paint.h"
#include "Player.h"
#include "Value.h"
#include <fstream>

using namespace std;

void printWelcome()
{
	cout << "Blackjack" << endl;
	cout << "Welcome to Blackjack" << endl;
}

void printWelcomePlayer(const char* playerName)
{
	cout << "You will play as " << playerName << ".";
}

//потребителят въвежда желаната големина на тестето
int getDeckSizeFromUserInput()
{
	cout << "Choose the size of the deck: " << endl;
	int size;
	cin >> size;

	return size;
}

//въвеждане на име и години на играча
Player createPlayerFromUserInput()
{
	Player player;
	char name[NAME_MAX_LENGTH];
	int years;
	cout << "Please, enter your name: " << endl;
	cin.ignore();
	cin.getline(name, NAME_MAX_LENGTH);
	
	player.setName(name);
	cout << "Please, enter your age: " << endl;
	cin >> years;
	player.setYears(years);

	return player;
}

Player newOrExistPlayer()
{
	int number;

	do
	{
		cout << "Do you want to create new player? " << endl;
		cout << "Press 1 for YES and 2 for NO. " << endl;
		cin >> number;
	}

	while (number != 1 && number != 2);

	Player player;

	if (number == 1)
	{
		player = createPlayerFromUserInput();
	}

	//Тук трябва да вземем играч от файла.
	else if (number == 2)
	{
		player = createPlayerFromUserInput();
	}

	return player;
}

//Съобщение, ако сме успяли да запазим информацията за играча във файл
void printSuccessMessage(const char* filePath)
{
	cout << endl;
	cout << "Successfully saved content in file: " << filePath << endl;
}

//Съобщение за грешка, ако не успеем да запазим информацията за играча във файл
void printErrorMessage(const char* filePath)
{
	cerr << endl;
	cerr << "There was a problem opening file with name: " << filePath << endl;
	cerr << endl;
}

//Запазване на информация във файл
void savePlayerInfoInFile(const char* outputFilePath, Player player)
{
	fstream outputFileStream;
	outputFileStream.open(outputFilePath, ios::out);

	if (outputFileStream.is_open())
	{
		outputFileStream << player;
		outputFileStream << "Coefficient of wins: " << player.coefficientOfWins() << endl;
		outputFileStream.close();
		printSuccessMessage(outputFilePath);
	}

	else
	{
		printErrorMessage(outputFilePath);
	}
}

void choiceOfPlayer()
{
	int number;
	Player player = Player();

	do
	{
		cout << "Hit/Stand/Probability" << endl;
		cout << "If you want to hit a card, press 1. " << endl;
		cout << "If you want to stand, press 2. " << endl;
		cout << "If you want probability, press 3. " << endl;
		cin >> number;
	}

	while (number != 1 && number != 2 && number != 3);

}

//Тестване на class Value
void testValue()
{
	Value defaultValue = Value();

	Value firstValue = Value("Three");
	cout << firstValue << endl;
	cout << firstValue.getPoints() << endl;

	Value secondValue = firstValue;
	cout << secondValue << endl;
	cout << secondValue.getPoints() << endl;

	Value thirdValue = Value(secondValue);
	cout << thirdValue << endl;
	cout << thirdValue.getPoints() << endl;
}

//Тестване на class Card
void testCard()
{
	Card firstCard = Card();
	Card secondCard = Card(Paint::Spade, Value("King"), "snumber");
	cout << secondCard << endl;

	Card thirdCard = secondCard;
	cout << thirdCard;

	Card fourthCard = Card(secondCard);
	cout << fourthCard;
}

//Тестване на class DeckOfCards
void testDeckOfCards()
{
	char seria[] = "Default";
	int cardsCount = 7;
	Card* cards = new Card[cardsCount];
	cards[0] = Card(Value("Four"), Paint::Club);
	cards[1] = Card(Value("King"), Paint::Spade);
	cards[2] = Card(Value("Three"), Paint::Club);
	cards[3] = Card(Value("Ten"), Paint::Spade);
	cards[4] = Card(Value("Four"), Paint::Diamond);
	cards[5] = Card(Value("Four"), Paint::Spade);
	cards[6] = Card(Value("Ace"), Paint::Heart);
	DeckOfCards firstDeck = DeckOfCards(cards, cardsCount, seria);

	DeckOfCards secondDeck = firstDeck;
	cout << secondDeck;

	DeckOfCards thirdDeck = DeckOfCards(secondDeck);
	cout << thirdDeck << endl;

	thirdDeck.swap(2, 4);
	cout << thirdDeck;

	Card card = thirdDeck.draw();
	cout << "The first card was:" << card << endl;
	cout << thirdDeck << endl;

	int spadesCount = thirdDeck.suit_count(Paint::Spade);
	cout << spadesCount << endl;

	int undrawnCards = thirdDeck.rank_count(Value("Four"));
	cout << undrawnCards << endl;
}

//Тестване на class Player
void testPlayer()
{
	Player firstPlayer = Player();
	Player secondPlayer = Player("Vesi", 19);
	cout << secondPlayer << endl;

	Player thirdPlayer = secondPlayer;
	cout << thirdPlayer << endl;

	Player fourthPlayer = Player(secondPlayer);
	cout << fourthPlayer << endl;
}

//Тестване на class Dealer
void testDealer()
{
	Dealer firstDealer = Dealer();
	Dealer secondDealer = Dealer(35);
	cout << secondDealer << endl;

	Dealer thirdDealer = secondDealer;
	cout << thirdDealer << endl;

	Dealer fourthDealer = Dealer(secondDealer);
	cout << fourthDealer << endl;
}

//Генериране на default deck 
void testGenerateDefaultDeck()
{
	DeckOfCards deck = DeckOfCards();
	deck.generateDefaultDeck();
	cout << deck << endl;
}

//Генериране на custom deck
void testGenerateCustomDeck()
{
	DeckOfCards firstDeck = DeckOfCards();
	firstDeck.generateCustomDeck(53, nullptr);
	cout << firstDeck << endl;

	DeckOfCards secondDeck = DeckOfCards();
	secondDeck.generateCustomDeck(530, "BIG");
	cout << secondDeck << endl;
}

void testSavePlayerInfo()
{
	const char* outputFilePath = "SaveInfo.txt";
	Player player = createPlayerFromUserInput();
	savePlayerInfoInFile(outputFilePath, player);
}

void testCreatePlayerFromUserInput()
{
	createPlayerFromUserInput();
}

void testNewOrExistPlayer()
{
	newOrExistPlayer();
}

void testClasses()
{
	// testValue();
	// testCard();
	// testDeckOfCards();
	// testPlayer();
	// testDealer();
}

void testGame()
{
	// testGenerateDefaultDeck();
	// testGenerateCustomDeck();
	// createPlayer();
	// testNewOrExistPlayer();
	// testCreatePlayerFromUserInput();
	// testSavePlayerInfo();
}

int main()
{
	// testClasses();
	// testGame();

	printWelcome();
	Player p = newOrExistPlayer();
	printWelcomePlayer(p.getName());
	int deckSize = getDeckSizeFromUserInput();

	Game game = Game();
	if (deckSize == MAX_DECK_SIZE)

	{
		game.startNewGameWithDefaultDeck();
	}

	else
	{
		game.startNewGameWithCustomDeck(deckSize, nullptr);
	}
	
	cout << "Start! " << endl;
	game.drawNextCard();
	//choiceOfPlayer();

	return 0;
}