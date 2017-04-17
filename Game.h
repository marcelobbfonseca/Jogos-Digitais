
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "State.h"

#ifndef MEUPROJETO_GAME_H
#define MEUPROJETO_GAME_H

class Game
{
public:
	Game(string,int, int);
	~Game();

	void Run();
	SDL_Renderer* GetRenderer();
	State& GetState();
	
	static Game& GetInstance();
private:

	static Game* instance;
	SDL_Window* window;
	SDL_Renderer* renderer;
	State* state;
	InputManager &inputManager;

};

#endif