#include <iostream>
#include "../Header/Player.h"
#include "../Header/Card.h"
#include <set>
#include <algorithm>



Player::~Player()
{
	for (Card* cardPtr : _hand) {
		delete cardPtr; cardPtr = nullptr;
	}
	for (Card* cardPtr : _tableau) {
		delete cardPtr; cardPtr = nullptr;
	}
}


Player::Player() : _totalScore(0)
{
	// Select a random name from the list of names
	std::string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge" };
	_name = names[rand() % 10];
}

void Player::addCardToHand(Card* cardPtr)
{
	_hand.emplace_back(cardPtr);
}

std::string Player::getName() const 
{
	return _name;
}

void Player::addCardToTableau(Card* cardPtr) 
{
	_tableau.emplace_back(cardPtr);
	for (int i = 0; i < _hand.size(); ++i) {
		if (_hand[i] == cardPtr) {
			_hand.erase(_hand.begin() + i);
		}
	}
}

void Player::printTableau()
{
	std::cout << "Tableau: " << std::endl;
	for (Card* cardPtr : _tableau) {
		std::cout << cardPtr->str() << std::endl;
	}
}

std::vector<Card*> Player::getHand()
{
	return _hand;
}

std::vector<Card*> Player::getTableau()
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

void Player::setHand(std::vector<Card*> newHand)
{
	_hand = newHand;
}

int Player::getTotalScore() {
	return _totalScore;
}

int Player::calculateRoundScore(std::vector<Card*> otherPlayerTableau)
{
	int roundScore = 0;
	std::set<CardType> scoredCards;
	for (Card* cardPtr : _tableau) {
		//checks if the cardPtr is already in scoredCards
		if (scoredCards.count(cardPtr->type()) == 0) {
			//scores the cardPtr
			roundScore += cardPtr->score(_tableau, otherPlayerTableau);
			//adds the cardPtr to the scoredCards set
			scoredCards.insert(cardPtr->type());
		}
	}

	//TODO : implement better fix for this . . .
	bool otherPlayerHasMakiRoll = (std::find_if(otherPlayerTableau.begin(), otherPlayerTableau.end(), [](const Card* cardPtr) {
		return cardPtr->type() == MakiRoll;
		}) != otherPlayerTableau.end());

	if (!scoredCards.count(MakiRoll) && otherPlayerHasMakiRoll) {
		roundScore += 3;
	}
	_totalScore += roundScore;
	return roundScore;
}



