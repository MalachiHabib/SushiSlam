#ifndef DUMPLING_CARD_H
#define DUMPLING_CARD_H

#include "../Card.h"
#include <string>

class DumplingCard : public Card {
	public:
	DumplingCard();

	CardType type() const;
	std::string str() const;
	int score(std::vector<Card*> playerOneTableau, std::vector<Card*> playerTwoTableau) const;
};
#endif