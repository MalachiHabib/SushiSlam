#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include <algorithm>
#include <random>
#include "Card.h"
#include "Player.h"
#include "../Header/CardTypes/MakiCard.h"

using namespace std;
class Game {
	private:
	vector<Card*> _gameDeck;
	vector<Player*> _players;
	int _currentRound = 1;
	int _currentTurn;
	Player* _currentPlayer;

	public:
	void initPlayers();
	int getUserInput(int playerCurrentHandSize);
	void startGame();
	void endGame();
	void createDeck();
	void shuffleDeck();
	void populateHands();
	void displayHand(Player* player);
	void startRound();
	void endRound();
	Player* getNextPlayer();
	void playTurn();
	void swapHands();
};

#endif
