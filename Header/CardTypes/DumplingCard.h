#pragma once
#include "../Card.h"
#include <string>
using namespace std;

class DumplingCard : public Card {
	public:
	DumplingCard();

	CardType type() const;
	string str() const;
	int score(vector<Card*> playerOneTableau, vector<Card*> playerTwoTableau) const;
};