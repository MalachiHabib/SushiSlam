#include <iostream>
#include <algorithm>
#include <random>
#include "../Header/Game.h"
#include "../Header/Card.h"
#include "../Header/CardTypes/DumplingCard.h"
#include "../Header/CardTypes/MakiCard.h"
#include "../Header/CardTypes/NigiriCard.h"
#include "../Header/CardTypes/SashimiCard.h"
#include "../Header/CardTypes/TempuraCard.h"

using namespace std;

void Game::initPlayers() {
	for (int i = 0; i < 2; i++) {
		_players.emplace_back(new Player());
	}
}

void Game::createDeck()
{
	for (int i = 0; i < 14; i++) {
		_gameDeck.emplace_back(new TempuraCard());
		_gameDeck.emplace_back(new SashimiCard());
		_gameDeck.emplace_back(new DumplingCard());
	}

	for (int i = 0; i < 12; i++) {
		_gameDeck.emplace_back(new MakiCard(2));
	}

	for (int i = 0; i < 10; i++) {
		_gameDeck.emplace_back(new NigiriCard(Salmon));
	}

	for (int i = 0; i < 8; i++) {
		_gameDeck.emplace_back(new MakiCard(3));
	}

	for (int i = 0; i < 6; i++) {
		_gameDeck.emplace_back(new MakiCard(1));
	}

	for (int i = 0; i < 5; i++) {
		_gameDeck.emplace_back(new NigiriCard(Egg));
		_gameDeck.emplace_back(new NigiriCard(Squid));
	}
}

void Game::shuffleDeck()
{
	shuffle(_gameDeck.begin(), _gameDeck.end(), default_random_engine(random_device()( )));
}

void Game::populateHands()
{
	for (Player* player : _players) {
		for (int i = 0; i < 10; i++) {
			player->addCardToHand(_gameDeck.at(i));
			_gameDeck.erase(_gameDeck.begin() + i);
		}
	}

}

void Game::displayHand(Player* player) {
	cout << "Current hand:" << endl;
	for (Card* card : player->getHand()) {
		cout << card->str() << endl;
	}
}

void Game::swapHands()
{
	displayHand(_players[0]);
	cout << "" << endl;
	vector<Card*> temp = _players[0]->getHand();
	_players[0]->setHand(_players[1]->getHand());
	_players[1]->setHand(temp);
	displayHand(_players[0]);
}
