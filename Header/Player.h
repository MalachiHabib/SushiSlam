#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"

using namespace std;

class Player {
	private:
	string _name;
	int _totalScore;
	vector<Card*> _tableau;
	vector<Card*> _hand;

	public:
	Player();
	void addCardToHand(Card* card);
	void addCardToTableau(Card* card);
	void clearTableau();
	void printTableau();
	void printHand();
	int calculateRoundScore(const vector<Card*>& otherTableau);
	string getName() const;
	string getCardDescription(int index) const;
};

#endif
