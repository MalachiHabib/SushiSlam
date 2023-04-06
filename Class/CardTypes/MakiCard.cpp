#include "../../Header/CardTypes/MakiCard.h"
#include <iostream>

MakiCard::MakiCard(int makiCount) : makiCount(makiCount) {
}

CardType MakiCard::type() const {
	static const CardType makiRollType = MakiRoll;
	return MakiRoll;
}

string MakiCard::str() const
{
	return "MakiRoll (" + std::to_string(makiCount) + ")";
}

int MakiCard::score(vector<Card*> playerOneTableau, vector<Card*> playerTwoTableau) const
{
	int playerOneCount = countMakis(playerOneTableau);
	int playerTwoCount = countMakis(playerTwoTableau);

	if (playerOneCount > playerTwoCount) {
		return 6;
	}
	return 3;
}

int MakiCard::countMakis(vector<Card*> tableau) const
{
	int numberOfMakis = 0;
	for (Card* card : tableau) {
		if (card->type() == MakiRoll) {
			numberOfMakis++;
		}
	}
	return numberOfMakis;
}


