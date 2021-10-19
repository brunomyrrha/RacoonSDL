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
	*mActionHandler = InputAction::NONE;
}

InputAction Input::MapKeyboardEvents(SDL_Keycode* keysym)
{
	switch (*keysym)
	{
	case SDLK_LCTRL: return InputAction::ACTION_A;
	case SDLK_SPACE: return InputAction::ACTION_B;
	case SDLK_UP: return InputAction::UP;
	case SDLK_DOWN: return InputAction::DOWN;
	case SDLK_LEFT: return InputAction::LEFT;
	case SDLK_RIGHT: return InputAction::RIGHT;
	default: return InputAction::NONE;
	}
}

void Input::HandleKeyboardState()
{
	const Uint8* keyStates = SDL_GetKeyboardState(NULL);
	if (keyStates[SDL_SCANCODE_LEFT]) *mActionHandler = InputAction::LEFT;
	if (keyStates[SDL_SCANCODE_RIGHT]) *mActionHandler = InputAction::RIGHT;
}