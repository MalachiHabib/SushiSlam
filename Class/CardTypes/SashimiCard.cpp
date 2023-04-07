#include "../../Header/CardTypes/SashimiCard.h"
#include <algorithm>

SashimiCard::SashimiCard()
{
}

CardType SashimiCard::type() const {
	return Sashimi;
}

string SashimiCard::str() const
{
	return "Sashimi";
}

int SashimiCard::score(vector<Card*> playerOneTableau, vector<Card*> playerTwoTableau) const
{
	int count = count_if(playerOneTableau.begin(), playerOneTableau.end(), [](Card* cardPtr) {
		return cardPtr->type() == Sashimi;
		});

	int score = (count == 3) ? 10 : 0;
	return score;
}
