#include "../../Header/CardTypes/MakiCard.h"
#include <iostream>

MakiCard::MakiCard(int makiCount) : makiCount(makiCount) {
}

CardType MakiCard::type() const {
	static const CardType makiRollType = MakiRoll;
	return MakiRoll;
}

string MakiCard::str() const
{
	return "MakiRoll (" + std::to_string(makiCount) + ")";
}

int MakiCard::score(vector<Card*> tableau, vector<Card*> otherPlayerTableau) const
{
	int cardScores[] = { 0, 0 };
	int counts[] = { 0, 0 };
	vector<Card*> tableaus[] = { tableau, otherPlayerTableau };

	for (int i = 0; i < 2; i++) {
		for (Card* card : tableaus[i]) {
			if (card->type() == MakiRoll) {
				counts[i]++;
			}
		}
	}

	cardScores[0] = (counts[0] != counts[1]) ? (counts[0] > counts[1] ? 6 : 3) : 0;
	cardScores[1] = (counts[0] != counts[1]) ? (counts[1] > counts[0] ? 6 : 3) : 0;
}

