#include "Renderer.h"
#include<SDL.h>

Renderer::Renderer(const char* title, int sizeW, int sizeH, bool* mGameIsRunning)
{
	window = SDL_CreateWindow(title,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		sizeW,
		sizeH,
		0
	);

	*mGameIsRunning = window != NULL;
	renderer = SDL_CreateRenderer(window,
		-1,
		SDL_RENDERER_ACCELERATED
	);
	*mGameIsRunning = renderer != NULL;
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void Renderer::Draw()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 1);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}
