#ifndef CARD_H
#define CARD_H
#include <string>
#include <vector>

enum CardType {
	MakiRoll, Tempura, Sashimi, Dumpling, Nigiri
};

class Card {
public:
	virtual ~Card() = default;
	virtual int score(std::vector<Card*> playerOneTableau, std::vector<Card*> playerTwoTableau) const = 0;
	virtual std::string str() const = 0;
	virtual CardType type() const = 0;
};
#endif
