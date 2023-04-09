#include "../../Header/CardTypes/NigiriCard.h"
#include <algorithm>
#include <numeric>


NigiriCard::NigiriCard(NigiriType nigiriType) : _nigiriType(nigiriType)
{
}

CardType NigiriCard::type() const {
	return Nigiri;
}

NigiriType NigiriCard::getNigiriType() const
{
	return _nigiriType;
}

std::string NigiriCard::str() const
{
	switch (_nigiriType) {
	case Egg: return "Nigiri (Egg)";
	case Squid: return "Nigiri (Squid)";
	case Salmon: return "Nigiri (Salmon)";
	default: return "----- Error -----";
	}
}

int NigiriCard::score(std::vector<Card*> playerOneTableau, std::vector<Card*> playerTwoTableau) const
{
	int score = 0;
	for (Card* card : playerOneTableau) {
		//count the card if its type is Nigiri
		if (card->type() == Nigiri) {
			//cast the card to a NigiriCard to use the methods
			NigiriCard* nigiriCard = dynamic_cast<NigiriCard*>(card);
			//score the card based on the NigiriType
			score +=
				(nigiriCard->getNigiriType() == Egg) ? 1 :
				(nigiriCard->getNigiriType() == Salmon) ? 2 :
				(nigiriCard->getNigiriType() == Squid) ? 3 : 0;
		}
	}
	return score;
}



