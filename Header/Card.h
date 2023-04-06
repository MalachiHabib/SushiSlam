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
	virtual int score(vector<Card*> playerOneTableau, vector<Card*> playerTwoTableau) const = 0;
	virtual string str() const = 0;
	virtual CardType type() const = 0;
};
