#ifndef RENDERER_H
#define RENDERER_H
class SDL_Window;
class SDL_Renderer;

class Renderer
{
public:
	Renderer(const char* title, int sizeW, int sizeH, bool* mGameIsRunning);
	~Renderer();
	void Draw();
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
};
#endif // !RENDERER_H


