
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"

#ifndef MEUPROJETO_GAME_H
#define MEUPROJETO_GAME_H

#include "StageState.h"
#include <stack>
#include "State.h"
#include "InputManager.h"
#include "Vec2.h"

class Game
{
public:
	Game(string,int, int);
	~Game();

	static Game& GetInstance();
	SDL_Renderer* GetRenderer();

	State& GetCurrentState();	
	void Push(State* state);
	void Run();
	float GetDeltaTime();
	SDL_Window* GetWindow();

	//StageState& GetState();

private:

	void CalculateDeltaTime();

	static Game* instance;
	SDL_Window* window;
	SDL_Renderer* renderer;
	//StageState* state;
	InputManager &inputManager;
	int frameStart;
	float dt;
	Game* istance;
	State* storedState;
	std::stack< std::unique_ptr<State> > stateStack;


};

#endif