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

/*
* @brief calculate the score of the players Tempura cards in their tableau
*
* This method iterates through player one's tableau
* It counts each instance of the Tempura card within the tableau
*
* @param playerOneTableau, a collection of Card pointers
* @return score, an integer representation of the players score based on the amount of Tempura cards they have
*/
int TempuraCard::score(std::vector<Card*> playerOneTableau, std::vector<Card*> playerTwoTableau) const
{
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
