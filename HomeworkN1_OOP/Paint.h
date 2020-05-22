#pragma once
#include <iostream>

using namespace std;

enum Paint 
{
	Spade,
	Club,
	Diamond,
	Heart
};

ostream& operator<<(ostream& os, Paint p);
