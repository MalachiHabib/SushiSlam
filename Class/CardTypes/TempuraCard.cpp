#include "../../Header/CardTypes/TempuraCard.h"

TempuraCard::TempuraCard()
{
}

CardType TempuraCard::type() const {
	return Tempura;
}

string TempuraCard::str() const
{
	return "Tempura";
}

int TempuraCard::score(vector<Card*> playerOneTableau, vector<Card*> playerTwoTableau) const
{
	int count = 0;
	int score = 0;
	for (Card* card : playerOneTableau) {
		if (card->type() == Tempura) {
			count++;
			if (count == 2) {
				count = 0;
				score += 5;
			}
		}
	}
	return score;
}
