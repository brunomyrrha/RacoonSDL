#ifndef INPUT_H
#define INPUT_H
#include "InputAction.h"
#include <SDL.h>

class Input
{
public:
	Input(bool* mGameIsRunning, InputAction* mActionHandler);
	~Input();
	void Update();
private:
	bool* mGameIsRunning = nullptr;
	InputAction* mActionHandler = nullptr;
	InputAction MapKeyboardEvents(SDL_Keycode* keysym);
	void HandleKeyboardState();
};
#endif // !INPUT_H

