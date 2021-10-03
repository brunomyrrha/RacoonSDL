#ifndef GAME_H
#define GAME_H
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
	Renderer* renderer;
	Input* input;
	Physics* physics;
};
#endif // !GAME_H

