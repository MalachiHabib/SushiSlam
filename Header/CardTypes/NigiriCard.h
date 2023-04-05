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
	string str() const;
	int score(vector<Card*> tableau, vector<Card*> otherPlayerTableau) const;

	private:
	NigiriType nigiriType;
};