#include "../../Header/CardTypes/SashimiCard.h"

SashimiCard::SashimiCard()
{
}

CardType SashimiCard::type() const {
	return Sashimi;
}

string SashimiCard::str() const
{
	return "MakiRoll()";
}
