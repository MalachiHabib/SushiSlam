#pragma once
#include "../Card.h"
#include <string>
using namespace std;

class MakiCard : public Card {
	public:
	MakiCard(int makiCount);

	CardType type() const;
	string str() const;
	int score(vector<Card*> playerOneTableau, vector<Card*> playerTwoTableau) const;
	int countMakis(vector<Card*> tableu) const;

	private:
	int makiCount;
};