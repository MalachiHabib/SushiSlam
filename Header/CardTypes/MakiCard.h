#ifndef MAKI_CARD_H
#define MAKI_CARD_H
#include "../Card.h"
#include <string>

class MakiCard : public Card {
	public:
	MakiCard(int makiCount);

	CardType type() const;
	std::string str() const;
	int score(std::vector<Card*> playerOneTableau, std::vector<Card*> playerTwoTableau) const;
	int countMakis(std::vector<Card*> tableu) const;

	private:
	int makiCount;
};
#endif