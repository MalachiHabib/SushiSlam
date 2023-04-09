#ifndef SASHIMI_CARD_H
#define SASHIMI_CARD_H
#include "../Card.h"
#include <string>

class SashimiCard : public Card {
public:
	SashimiCard();

	CardType type() const;
	std::string str() const;
	int score(std::vector<Card*> playerOneTableau, std::vector<Card*> playerTwoTableau) const;
};
#endif