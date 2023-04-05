#pragma once
#include "../Card.h"
#include <string>
using namespace std;

class DumplingCard : public Card {
	public:
	DumplingCard();

	CardType type() const;
	string str() const;
	int score(vector<Card*> tableau, vector<Card*> otherPlayerTableau) const;
};