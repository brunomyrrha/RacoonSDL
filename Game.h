#ifndef GAME_H
#define GAME_H
#include "InputAction.h"

class Renderer;
class Input;
class Physics;

class Game
{
public:
	Game();
	~Game();
	void Run();
	bool IsRunning() { return mGameIsRunning; };
private:
	bool mGameIsRunning = true;
	InputAction mInputAction = NONE;
	Renderer* renderer = nullptr;
	Input* input = nullptr;
	Physics* physics = nullptr;
};
#endif // !GAME_H

