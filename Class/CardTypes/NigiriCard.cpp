#include "../../Header/CardTypes/NigiriCard.h"
#include <algorithm>
#include <numeric>

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
	int score = accumulate(playerOneTableau.begin(), playerOneTableau.end(), 0, [](int current_score, Card* card) {
		if (card->type() == Nigiri) {
			NigiriCard* nigiriCard = dynamic_cast<NigiriCard*>(card);
			if (nigiriCard) {
				return current_score +
					(nigiriCard->getNigiriType() == Egg) ? 1 :
					(nigiriCard->getNigiriType() == Salmon) ? 2 :
					(nigiriCard->getNigiriType() == Squid) ? 3 : 0;
			}
		}
		return current_score;
		});
	return score;
}



