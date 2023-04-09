#include "../Header/Game.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

int main() {
	Game* game = new Game;
	game->play();

	delete game;
	_CrtDumpMemoryLeaks();
	return 0;
}