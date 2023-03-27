#pragma once

#include <string>
#include <vector>

using namespace std;

enum CardType {
	MakiRoll, Tempura, Sashimi, Dumpling, Nigiri
};

class Card {
	public:
	virtual ~Card() {}
	virtual string str() const = 0;
	virtual CardType type() const = 0;
};
