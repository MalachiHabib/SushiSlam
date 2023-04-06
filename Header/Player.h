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
	vector<Card*> getHand();
	vector<Card*> getTableau();
	void setHand(vector<Card*> hand);
	int calculateRoundScore(vector<Card*> otherPlayerTableau);
	string getName() const;

};

#endif
