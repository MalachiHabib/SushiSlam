#include "../../Header/CardTypes/NigiriCard.h"

NigiriCard::NigiriCard(NigiriType nigiriType) : nigiriType(nigiriType)
{
}

CardType NigiriCard::type() const {
	return Nigiri;
}

NigiriType NigiriCard::getNigiriType() const
{
	return nigiriType;
}

string NigiriCard::str() const
{
	switch (nigiriType) {
	case Egg: return "Nigiri (Egg)";
	case Squid: return "Nigiri (Squid)";
	case Salmon: return "Nigiri (Salmon)";
	default: return "----- Error -----";
	}
}

int NigiriCard::score(vector<Card*> playerOneTableau, vector<Card*> playerTwoTableau) const
{
	int count = 0;
	int score = 0;

	for (Card* card : playerOneTableau) {
		if (card->type() == Nigiri) {
			NigiriCard* nigiriCard = dynamic_cast<NigiriCard*>(card);
			score += (nigiriCard->getNigiriType() == Egg) ? 1 :
					 (nigiriCard->getNigiriType() == Salmon) ? 2 :
					 (nigiriCard->getNigiriType() == Squid) ? 3 : 0;
		}
	}
	return score;
}



