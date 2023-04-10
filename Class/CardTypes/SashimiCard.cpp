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

/*
* @brief calculate the score of the players Sushimi cards in their tableau
* 
* This method iterates through player one's tableau
* It counts each instance of the Sashimi card within the tableau
* 
* @param playerOneTableau, a collection of Card pointers
* @return score, an integer representation of the players score based on the amount of Sashimi cards they have
*/
int SashimiCard::score(std::vector<Card*> playerOneTableau, std::vector<Card*> playerTwoTableau) const
{
	int count = count_if(playerOneTableau.begin(), playerOneTableau.end(), [](Card* cardPtr) {
		return cardPtr->type() == Sashimi;
		});

	int score = (count >= 3 && count < 6) ? 10
			  : (count >= 6 && count < 9) ? 20
			  : (count > 9) ? 30
			  : 0;
	return score;
}
