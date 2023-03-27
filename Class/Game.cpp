#include <iostream>
#include <algorithm>
#include <random>
#include "../Header/Game.h"
#include "../Header/Card.h"
#include "../Header/CardTypes/MakiCard.h"

using namespace std;
void Game::initPlayers() {
	Card* makiRoll = new MakiCard(2);
	cout << makiRoll->type() << endl;
	srand(time(NULL));
	Player* one = new Player();
	Player* two = new Player();
	one->addCardToTableau(makiRoll);
	cout << two->getName() + one->getName() << endl;
	one->printTableau();
	cout << makiRoll->str() << endl;

}

void Game::createDeck()
{
	vector<MakiCard> makiCards;

	for (int i = 0; i < 12; i++) {
		makiCards.push_back(MakiCard(2));
	}

	for (int i = 0; i < 8; i++) {
		makiCards.push_back(MakiCard(3));
	}

	for (int i = 0; i < 6; i++) {
		makiCards.push_back(MakiCard(1));
	}

	for (const MakiCard& makiCard : makiCards) {
		cout << makiCard.str() << endl;
	}
}
