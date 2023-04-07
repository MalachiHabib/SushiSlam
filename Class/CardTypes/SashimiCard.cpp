#include "../../Header/CardTypes/SashimiCard.h"

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
	int count = 0;
	int score = 0;

	for (Card* card : playerOneTableau) {
		if (card->type() == Sashimi) {
			count++;
			if (count == 3) {
				count = 0;
				score += 10;
			}
		}
		return score;
	}
	return score;
}
