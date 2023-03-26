#include <iostream>
#include "player.h"
#include "Card.h"


using namespace std;

Player::Player() : _totalScore( 0 ) {
	// Select a random name from the list of names
	string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge" };
	_name = names[rand() % 10];
}

string Player::getName() const {
	return _name;
}

void Player::addCardToTableau( Card* card ) {
	_tableau.push_back( card );
}

void Player::printTableau()
{
	for (Card* card : _tableau) {

		switch (card->type()) {
			case CardType::MakiRoll: cout << "MakiRoll" << endl;
		}
	}
}



