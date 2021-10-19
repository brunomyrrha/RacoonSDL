#include "Game.h"
#include "Renderer.h"
#include "Input.h"
#include "Physics.h"
#include <SDL.h>
#include <iostream>

Game::Game()
{
	mGameIsRunning = SDL_Init(SDL_INIT_EVERYTHING) == 1;
	renderer = new Renderer("Ghost Racoon",
		1280,
		720,
		&mGameIsRunning
	);
	input = new Input(&mGameIsRunning, &mInputAction);
	physics = new Physics();
}

Game::~Game()
{
	delete(input);
	delete(physics);
	delete(renderer);	
	SDL_Quit();
}

void Game::Run()
{
	input->Update();
	physics->Calculate();
	renderer->Draw();
}