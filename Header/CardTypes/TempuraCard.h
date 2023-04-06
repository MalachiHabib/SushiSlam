#pragma once
#include "../Card.h"
#include <string>
using namespace std;

class TempuraCard : public Card {
public:
	TempuraCard();

	CardType type() const;
	string str() const;
	int score(vector<Card*> playerOneTableau, vector<Card*> playerTwoTableau) const;
};