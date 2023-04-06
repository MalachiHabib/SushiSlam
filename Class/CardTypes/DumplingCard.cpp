#include "../../Header/CardTypes/DumplingCard.h"

DumplingCard::DumplingCard()
{
}

CardType DumplingCard::type() const {
	return Dumpling;
}

string DumplingCard::str() const
{
	return "Dumpling";
}

int DumplingCard::score(vector<Card*> playerOneTableau, vector<Card*> playerTwoTableau) const
{
	int count = 0;
	int score = 0;
	for (Card* card : playerOneTableau) {
		if (card->type() == Dumpling) {
			count++;
			score = count == 1 ? 1 :
					count == 2 ? 3 :
					count == 3 ? 6 :
					count == 4 ? 10 :
					count > 4 ? 15 : 0;
		}
	}
	return score;
}

