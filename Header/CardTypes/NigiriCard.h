#pragma once
#pragma once
#include "../Card.h"
#include <string>

using namespace std;

enum NigiriType {
	Egg, Squid, Salmon
};

class NigiriCard : public Card {
public:
	NigiriCard(NigiriType nigiriType);

	CardType type() const;
	NigiriType getNigiriType() const;
	string str() const;
	int score(vector<Card*> playerOneTableau, vector<Card*> playerTwoTableau) const;

private:
	NigiriType nigiriType;
};