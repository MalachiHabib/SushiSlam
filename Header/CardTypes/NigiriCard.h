#ifndef NIGIRI_CARD_H
#define NIGIRI_CARD_H
#include "../Card.h"
#include <string>

enum NigiriType {
	Egg, Squid, Salmon
};

class NigiriCard : public Card {
public:
	NigiriCard(NigiriType _nigiriType);

	CardType type() const;
	NigiriType getNigiriType() const;
	std::string str() const;
	int score(std::vector<Card*> playerOneTableau, std::vector<Card*> playerTwoTableau) const;

private:
	NigiriType _nigiriType;
};
#endif