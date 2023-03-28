#include <iostream>
#include "../Header/Player.h"
#include "../Header/Card.h"


using namespace std;

Player::Player() : _totalScore(0) {
	// Select a random name from the list of names
	string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge" };
	_name = names[rand() % 10];
}

void Player::addCardToHand(Card* card)
{
	_hand.emplace_back(card);
}

string Player::getName() const {
	return _name;
}

void Player::addCardToTableau(Card* card) {
	_tableau.emplace_back(card);
	for (int i = 0; i < _hand.size(); i++) {
		if (_hand[i] == card) {
			_hand.erase(_hand.begin() + i);
		}
	}
}

void Player::printTableau()
{
	cout << "Tableau: " << endl;
	for (Card* card : _tableau) {
		cout << card->str() << endl;
	}
}

vector<Card*> Player::getHand()
{
	if (!(_hand.empty())) {
		vector<Card*> currentHand;
		for (Card* card : _hand) {
			currentHand.emplace_back(card);
		}
		return currentHand;
	}
}

void Player::setHand(vector<Card*> newHand)
{
	_hand = newHand;
}



