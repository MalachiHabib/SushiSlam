#include "../../Header/CardTypes/DumplingCard.h"

DumplingCard::DumplingCard()
{
}

CardType DumplingCard::type() const {
	return Dumpling;
}

string DumplingCard::str() const
{
	return "Dumpling";
}
