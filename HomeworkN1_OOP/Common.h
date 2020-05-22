#pragma once
#include <utility>

using namespace std;

const int VALUES_SIZE = 13;

const int MAX_DECK_SIZE = 52;

const int MAX_SERIA_LENGTH = 10;

const int MAX_SERIAL_NUMBER_LENGTH = 15;

const int MAX_SYMBOL_NAME_LENGTH = 6;

const int NAME_MAX_LENGTH = 60;

const pair<const char*, int> values[] = 
{
					pair<const char*,int>("Two", 2),
					pair<const char*,int>("Three", 3),
					pair<const char*,int>("Four", 4),
					pair<const char*,int>("Five", 5),
					pair<const char*,int>("Six", 6),
					pair<const char*,int>("Seven", 7),
					pair<const char*,int>("Eight", 8),
					pair<const char*,int>("Nine", 9),
					pair<const char*,int>("Ten", 10),
					pair<const char*,int>("Jack", 10),
					pair<const char*,int>("Queen", 10),
					pair<const char*,int>("King", 10),
					pair<const char*,int>("Ace", 11)
};

int mystrlen(const char* str);

void mystrcpy(char*& destination, const char* source);


