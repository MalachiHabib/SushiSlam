#include "../../Header/CardTypes/NigiriCard.h"

NigiriCard::NigiriCard(NigiriType nigiriType) : nigiriType(nigiriType)
{
}

CardType NigiriCard::type() const {
	return Nigiri;
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


