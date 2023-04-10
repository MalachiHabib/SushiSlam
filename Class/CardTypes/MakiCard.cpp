#include "../../Header/CardTypes/MakiCard.h"
#include <iostream>

MakiCard::MakiCard(int _makiCount) : _makiCount(_makiCount) 
{
}

CardType MakiCard::type() const 
{
	static const CardType makiRollType = MakiRoll;
	return MakiRoll;
}

std::string MakiCard::str() const
{
	return "MakiRoll (" + std::to_string(_makiCount) + ")";
}

int MakiCard::score(std::vector<Card*> playerOneTableau, std::vector<Card*> playerTwoTableau) const
{
	int playerOneCount = countMakis(playerOneTableau);
	int playerTwoCount = countMakis(playerTwoTableau);

	if (playerOneCount > playerTwoCount) {
		return 6;
	}
	return 3;
}

int MakiCard::countMakis(std::vector<Card*> tableau) const
{
	int numberOfMakis = 0;
	for (Card* card : tableau) {
		if (card->type() == MakiRoll) {
			MakiCard* makiCard = dynamic_cast<MakiCard*>(card);
			numberOfMakis+= makiCard->_makiCount;
		}
	}
	return numberOfMakis;
}


