#include "../../Header/CardTypes/NigiriCard.h"

NigiriCard::NigiriCard(NigiriType nigiriType) : nigiriType(nigiriType)
{
}

CardType NigiriCard::type() const {
	return Dumpling;
}

string NigiriCard::str() const
{
	return "MakiRoll()";
}
