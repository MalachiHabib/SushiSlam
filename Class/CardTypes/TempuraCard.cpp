#include "../../Header/CardTypes/TempuraCard.h"
#include <algorithm>


TempuraCard::TempuraCard()
{
}

CardType TempuraCard::type() const 
{
	return Tempura;
}

std::string TempuraCard::str() const
{
	return "Tempura";
}

int TempuraCard::score(std::vector<Card*> playerOneTableau, std::vector<Card*> playerTwoTableau) const
{
	//counts how many Tempura cards are int he player ones tableau
	int count = count_if(playerOneTableau.begin(), playerOneTableau.end(), [](Card* cardPtr) {
		return cardPtr->type() == Tempura;
		});

	int score = (count >= 2 && count < 4) ? 5
			  : (count >= 4 && count < 6) ? 10
			  : (count >= 6 && count < 8) ? 15
			  : (count >= 8 && count < 10) ? 20
			  : (count >= 10) ? 25
		  	  : 0;
	return score;
}
