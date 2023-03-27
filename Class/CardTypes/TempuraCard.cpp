#include "../../Header/CardTypes/TempuraCard.h"

TempuraCard::TempuraCard()
{
}

CardType TempuraCard::type() const {
	return Tempura;
}

string TempuraCard::str() const
{
	return "MakiRoll()";
}
