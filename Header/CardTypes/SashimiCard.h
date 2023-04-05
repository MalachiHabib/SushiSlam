#pragma once
#include "../Card.h"
#include <string>
using namespace std;

class SashimiCard : public Card {
	public:
	SashimiCard();

	CardType type() const;
	string str() const;
	int score(vector<Card*> tableau, vector<Card*> otherPlayerTableau) const;S
};