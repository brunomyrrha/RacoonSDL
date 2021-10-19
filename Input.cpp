#include "Input.h"
#include <iostream>

Input::Input(bool* mGameIsRunning, InputAction* mActionHandler)
{
	this->mGameIsRunning = mGameIsRunning;
	this->mActionHandler = mActionHandler;
}

Input::~Input()
{
	*mGameIsRunning = false;
}

void Input::Update()
{
	HandleKeyboardState();
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type) {
		case SDL_QUIT:
			*mGameIsRunning = false;
			break;
		case SDL_KEYDOWN:
			*mActionHandler = MapKeyboardEvents(&event.key.keysym.sym);
		default:
			break;
		}
	}
	*mActionHandler = NONE;
}

InputAction Input::MapKeyboardEvents(SDL_Keycode* keysym)
{
	switch (*keysym)
	{
	case SDLK_LCTRL: return ACTION_A;
	case SDLK_SPACE: return ACTION_B;
	case SDLK_UP: return UP;
	case SDLK_DOWN: return DOWN;
	case SDLK_LEFT: return LEFT;
	case SDLK_RIGHT: return RIGHT;
	default: return NONE;
	}
}

void Input::HandleKeyboardState()
{
	const Uint8* keyStates = SDL_GetKeyboardState(NULL);
	if (keyStates[SDL_SCANCODE_LEFT]) *mActionHandler = LEFT;
	if (keyStates[SDL_SCANCODE_RIGHT]) *mActionHandler = RIGHT;
}