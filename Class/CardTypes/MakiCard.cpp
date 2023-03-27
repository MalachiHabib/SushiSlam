#include "../../Header/CardTypes/MakiCard.h"
#include <iostream>

int amountOfCards = 0;

MakiCard::MakiCard(int makiCount) : makiCount(makiCount) {
	amountOfCards++;
}

CardType MakiCard::type() const {
	return MakiRoll;
}

string MakiCard::str() const
{
	return "MakiRoll(" + std::to_string(makiCount) + ")";
}
