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
	int _currentRound = 0;
	int _maxRounds = 3;
	int _currentTurn = 0;
	Player* _currentPlayer;

public:
	~Game();
	void initPlayers();
	int getUserInput(int playerCurrentHandSize);
	void createDeck();
	void shuffleDeck();
	void getRoundScore();
	void populateHands();
	void displayHand(Player* player);
	void playTurn();
	void playRound();
	void swapHands();
};

#endif
