#include <iostream>
#include "../Header/Player.h"
#include "../Header/Card.h"
#include <set>
#include <algorithm>


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
	return _hand;
}

vector<Card*> Player::getTableau()
{
	return _tableau;
}

void Player::clearTableau()
{
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
	for (Card* card : _tableau) {
		//checks if the card is already in scoredCards
		if (scoredCards.count(card->type()) == 0) {
			//scores the card
			_totalScore += card->score(_tableau, otherPlayerTableau);
			//adds the card to the scoredCards set
			scoredCards.insert(card->type());
		}
	}

	//TODO : implement better fix for this . . .
	bool otherPlayerHasMakiRoll = (std::find_if(otherPlayerTableau.begin(), otherPlayerTableau.end(), [](const Card* card) {
		return card->type() == MakiRoll;
		}) != otherPlayerTableau.end());

	if (!scoredCards.count(MakiRoll) && otherPlayerHasMakiRoll) {
		_totalScore += 3;
	}

	return _totalScore;
}



