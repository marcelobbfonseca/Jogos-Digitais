#include <iostream>
using namespace std;
#include "Game.h"

//1 duvida 90%
Game* Game::instance=nullptr;

Game::Game(string title, int width, int height){
	bool funfou = true;

	if(instance != nullptr){
		instance = this;
	}else{
		cout << "\nERRO:instance diferente de null "<< __LINE__ << __FILE__<< endl;
		showGameError();
	}
	initialize();
	
	const char *const_title = title.c_str();
	window = SDL_CreateWindow(const_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width,height ,0);
	
	if(window != nullptr){
		renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
		if(renderer == nullptr){
			cout <<__LINE__<<" "<< __FILE__<< endl;
			showGameError();	
		}
	}else{
		cout <<__LINE__<<" "<< __FILE__<< endl;
		showGameError();		
	}
	
	state = new State();
	cout << "Alooo "<< __LINE__ << __FILE__<< endl;
}

void Game::initialize(){
	int sdl_init, img_init;

	sdl_init = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
	img_init = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);

	if(sdl_init || !img_init){
		cout <<__LINE__<<" " << __FILE__<< endl;
		showGameError();
	}
	return;
}

void Game::showGameError(){
	cout << SDL_GetError() << " "<< __LINE__ << __FILE__<< endl;
	exit(1);
}


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
		//pt 1
		//pt 2
		//pt 3call update e render
		state->Update(0.0);
		state->Render();
		SDL_RenderPresent(renderer);//update screen
		
		/*		*		*		*		*		*		*		*		*		*
		 *Delay processor in 33 milisecound for the next frame(1 frame per 33ms)* 
		 *Should be around 30 FPS												*
		 * 		*		*		*		*		*		*		*		*		*/
		SDL_Delay(33); 

		
		if(state->QuitRequested())
			break;
	}//end while main loop
}

Game::~Game(){

	IMG_Quit();
	delete[] state;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
