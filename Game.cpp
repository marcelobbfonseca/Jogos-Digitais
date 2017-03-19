#include <iostream>
using namespace std;

#include "Game.h"

Game::Game(string title, int width, int height){
	bool funfou = true;
	Uint32 flags=0;

	if(instance != nullptr){
		instance = this;
	}
	SDL_initialize();
	
	const char *const_title = title.c_str();
	window = SDL_CreateWindow(const_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width,height ,0);
	if(window != nullptr){
		flags = SDL_RENDERER_SOFTWARE | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE;
		renderer = SDL_CreateRenderer(window,-1,flags);
		if(renderer == nullptr){
			cout << SDL_GetError() << endl;
			exit(1);		
		}
	}else{
		cout << SDL_GetError() << endl;
		exit(1);		
	}
	state = nullptr;//inicializar state com???
}

void Game::SDL_initialize(){
	int sdl_init, img_init;

	sdl_init = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
	img_init = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);

	if(sdl_init || !img_init){
		cout << SDL_GetError() << endl;
		exit(1);
	}

	return;
}
//Game*
Game& Game::GetInstance(){
	return *instance;
}

State& Game::GetState(){
	return *state;
}


SDL_Renderer* Game::GetRenderer(){
	return renderer;
}
void Game::Run(){
	while(state->QuitRequested()==false){
		//call update e render
		state->Update(0.0);
		state->Render();
		SDL_RenderPresent(renderer);//update screen
		
		/*		*		*		*		*		*		*		*		*		*
		 *Delay processor in 33 milisecound for the next frame(1 frame per 33ms)* 
		 *Should be around 30 FPS												*
		 * 		*		*		*		*		*		*		*		*		*/
		SDL_Delay(33); 

		

	}//end while main loop
}

Game::~Game(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
}
