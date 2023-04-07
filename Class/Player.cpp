#include <iostream>
#include "../Header/Player.h"
#include "../Header/Card.h"
#include <set>
#include <algorithm>

using namespace std;

Player::~Player()
{
	for (Card* cardPtr : _hand) {
		delete cardPtr; cardPtr = nullptr;
	}
	for (Card* cardPtr : _tableau) {
		delete cardPtr; cardPtr = nullptr;
	}
}


Player::Player() : _totalScore(0) {
	// Select a random name from the list of names
	string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge" };
	_name = names[rand() % 10];
}

void Player::addCardToHand(Card* cardPtr)
{
	_hand.emplace_back(cardPtr);
}

string Player::getName() const {
	return _name;
}

void Player::addCardToTableau(Card* cardPtr) {
	_tableau.emplace_back(cardPtr);
	for (int i = 0; i < _hand.size(); i++) {
		if (_hand[i] == cardPtr) {
			_hand.erase(_hand.begin() + i);
		}
	}
}

void Player::printTableau()
{
	cout << "Tableau: " << endl;
	for (Card* cardPtr : _tableau) {
		cout << cardPtr->str() << endl;
	}
}

vector<Card*> Player::getHand()
{
	return _hand;
}

vector<Card*> Player::getTableau()
{
	return _tableau;
}

void Player::clearTableau()
{
	for (Card* cardPtr : _tableau) {
		delete cardPtr; cardPtr = nullptr;
	}
	_tableau.clear();
}

void Player::setHand(vector<Card*> newHand)
{
	_hand = newHand;
}

int Player::calculateRoundScore(vector<Card*> otherPlayerTableau)
{
	_totalScore = 0;
	set<CardType> scoredCards;
	for (Card* cardPtr : _tableau) {
		//checks if the cardPtr is already in scoredCards
		if (scoredCards.count(cardPtr->type()) == 0) {
			//scores the cardPtr
			_totalScore += cardPtr->score(_tableau, otherPlayerTableau);
			//adds the cardPtr to the scoredCards set
			scoredCards.insert(cardPtr->type());
		}
	}

	//TODO : implement better fix for this . . .
	bool otherPlayerHasMakiRoll = (std::find_if(otherPlayerTableau.begin(), otherPlayerTableau.end(), [](const Card* cardPtr) {
		return cardPtr->type() == MakiRoll;
		}) != otherPlayerTableau.end());

	if (!scoredCards.count(MakiRoll) && otherPlayerHasMakiRoll) {
		_totalScore += 3;
	}

	return _totalScore;
}



