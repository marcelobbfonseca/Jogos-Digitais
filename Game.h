
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

	float GetDeltaTime();
private:

	static Game* instance;
	SDL_Window* window;
	SDL_Renderer* renderer;
	State* state;
	InputManager &inputManager;
	//t4
	void CalculateDeltaTime();

	int frameStart;
	float dt;


};

#endif