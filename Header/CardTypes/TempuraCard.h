#ifndef TEMPURA_CARD_H
#define TEMPURA_CARD_H
#include "../Card.h"
#include <string>

class TempuraCard : public Card {
public:
	TempuraCard();

	CardType type() const;
	std::string str() const;
	int score(std::vector<Card*> playerOneTableau, std::vector<Card*> playerTwoTableau) const;
};
#endif