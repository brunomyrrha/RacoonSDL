#include "Input.h"
#include <SDL.h>

Input::Input(bool* mGameIsRunning)
{
	this->mGameIsRunning = mGameIsRunning;
}

Input::~Input()
{

}

void Input::Update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type) {
		case SDL_QUIT:
			*mGameIsRunning = false;
			break;
		}
	}
}
