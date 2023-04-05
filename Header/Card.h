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
	virtual int score(vector<Card*> tableau, vector<Card*> otherPlayerTableau) const = 0;
	virtual string str() const = 0;
	virtual CardType type() const = 0;
};
