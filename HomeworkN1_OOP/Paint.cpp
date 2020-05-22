#include <iostream>
#include <vector>
#include <string>
#include "Paint.h"

using namespace std;

ostream& operator<<(ostream& os, Paint p)
{
	switch (p)
	{
	case Paint::Spade: os << "Spade"; break;
	case Paint::Club: os << "Club"; break;
	case Paint::Diamond: os << "Diamond"; break;
	case Paint::Heart: os << "Heart"; break;
	}
	return os;
}
