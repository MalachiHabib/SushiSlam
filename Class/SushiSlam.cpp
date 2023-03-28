#include "../Header/Game.h"

int main() {
	Game game;
	game.initPlayers();
	game.createDeck();
	game.shuffleDeck();
	game.populateHands();
	game.playTurn();
	return 0;
}