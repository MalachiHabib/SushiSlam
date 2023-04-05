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

int DumplingCard::score(vector<Card*> tableau, vector<Card*> otherPlayerTableau) const
{

}

