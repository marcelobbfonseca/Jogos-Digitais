#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#include "Resources.h"
#include "Game.h"
#include "error.h"
Game* Game::instance= nullptr;

Game::Game(string title, int width, int height){


	if(nullptr != instance ){
		printError(__LINE__, "Exista uma segunda instancia do jogo! " ,__FILE__);
	}else{
		instance = this;
	}
	initialize();//inicializa SDL e IMG init
	
	const char *const_title = title.c_str();
	window = SDL_CreateWindow(const_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width,height ,0);
	
	if(window != nullptr){
		renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
		if(renderer == nullptr){
			printError(__LINE__, SDL_GetError() ,__FILE__);	
		}
	}else{
		printError(__LINE__, SDL_GetError() ,__FILE__);	
	}

	srand(time(NULL));

	state = new State();
}

void Game::initialize(){
	unsigned int img_init;

	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER))
		printError(__LINE__, SDL_GetError() ,__FILE__);

	img_init = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);

	if(img_init==false)
		printError(__LINE__, SDL_GetError() ,__FILE__);
	
	return;
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
	state->LoadAssets();

	//main loop
	while(state->QuitRequested()==false){
		/*pt 1 */
		
		/*pt 2 */

		/*pt 3call update e render */
		state->Update();
		state->Render();
		SDL_RenderPresent(renderer);//update screen   //nao eh isso
		
		
		/*		*		*		*		*		*		*		*		*		*
		 *Delay processor in 33 milisecound for the next frame(1 frame per 33ms)* 
		 *Should be around 30 FPS												*
		 * 		*		*		*		*		*		*		*		*		*/
		SDL_Delay(33); 

	}//end while main loop
	Resources::ClearImages();
}

Game::~Game(){

	IMG_Quit();
	delete state;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	
}


