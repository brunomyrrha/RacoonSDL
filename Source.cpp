#include "Game.h"

int main(int argc, char* argv[])
{
	Game* game = new Game();
	while (game->IsRunning()) {
		game->Run();
	}
	return 0;
}