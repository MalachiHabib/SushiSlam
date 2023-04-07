#include "../../Header/CardTypes/DumplingCard.h"
#include <algorithm>

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

	int count = count_if(playerOneTableau.begin(), playerOneTableau.end(), [](Card* cardPtr) {
		return cardPtr->type() == Dumpling;
		});

	int score = count == 1 ? 1 :
				count == 2 ? 3 :
				count == 3 ? 6 :
				count == 4 ? 10 :
				count > 4 ? 15 : 0;

	return score;
}

