#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "Card.h"

class Player {
private:
	std::string _name;
	int _totalScore;
	std::vector<Card*> _tableau;
	std::vector<Card*> _hand;

public:
	Player();
	~Player();

	std::string getName() const;

	std::vector<Card*> getHand();
	void addCardToHand(Card* card);
	void setHand(std::vector<Card*> hand);

	void addCardToTableau(Card* card);
	void clearTableau();
	void printTableau();
	std::vector<Card*> getTableau();

	int getTotalScore();
	int calculateRoundScore(std::vector<Card*> otherPlayerTableau);
};
#endif