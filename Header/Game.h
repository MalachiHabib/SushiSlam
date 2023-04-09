#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <ctime>
#include <algorithm>
#include <random>
#include "Card.h"
#include "Player.h"
#include "../Header/CardTypes/MakiCard.h"

class Game {
private:
	std::vector<Card*> _gameDeck;
	std::vector<Player*> _players;
	Player* _currentPlayer;

	int _currentRound = 0;
	int _maxRounds = 3;
	int _currentTurn = 0;

public:
	~Game();

	void initPlayers();
	int getUserInput(int playerCurrentHandSize);
	void displayHand(Player* player);

	void play();
	void playTurn();

	void getRoundScore();
	void getTotalScore();

	void createDeck();
	void shuffleDeck();
	void populateHands();
	void swapHands();
};

#endif
