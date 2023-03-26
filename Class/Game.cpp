#include <iostream>
#include <algorithm>
#include <random>
#include "../Header/Game.h"
#include "../Header/Card.h"
#include "../Header/CardTypes/MakiCard.h"

void Game::initPlayers() {
	Card* makiRoll = new MakiCard();
	cout << makiRoll->type() << endl;
	srand( time( NULL ) );
	Player* one = new Player();
	Player* two = new Player();
	one->addCardToTableau( makiRoll );
	// Create a new MakiRollCard instance and add it to player one's tableau
	cout << two->getName() + one->getName() << endl;
	one->printTableau();
}