#include "../../Header/CardTypes/SashimiCard.h"
#include <algorithm>


SashimiCard::SashimiCard()
{
}

CardType SashimiCard::type() const 
{
	return Sashimi;
}

std::string SashimiCard::str() const
{
	return "Sashimi";
}

int SashimiCard::score(std::vector<Card*> playerOneTableau, std::vector<Card*> playerTwoTableau) const
{
	//counts how many Sashimi cards are int he player ones tableau
	int count = count_if(playerOneTableau.begin(), playerOneTableau.end(), [](Card* cardPtr) {
		return cardPtr->type() == Sashimi;
		});

	int score = (count >= 3 && count < 6) ? 10
			  : (count >= 6 && count < 9) ? 20
			  : (count > 9) ? 30
			  : 0;

	return score;
}
