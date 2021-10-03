#include "Game.h"
#include "Renderer.h"
#include "Input.h"
#include "Physics.h"
#include <SDL.h>

Game::Game()
{
	mGameIsRunning = SDL_Init(SDL_INIT_EVERYTHING) == 1;
	renderer = new Renderer("Ghost Racoon",
		1280,
		720,
		&mGameIsRunning
	);
	input = new Input(&mGameIsRunning);
	physics = new Physics();
}

Game::~Game()
{
	input->~Input();
	renderer->~Renderer();
	SDL_Quit();
}

void Game::Run()
{
	input->Update();
	physics->Calculate();
	renderer->Draw();
}