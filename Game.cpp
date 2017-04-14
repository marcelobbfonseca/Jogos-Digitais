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
		ErrorExit(__LINE__, "Exista uma segunda instancia do jogo! " ,__FILE__);
	}else{
		instance = this;
	}

	if(0 != SDL_Init(SDL_INIT_VIDEO))//erro dando aqui!!!
		ErrorExit(__LINE__, SDL_GetError() ,__FILE__);

	int img_init= IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);

	if(0 == img_init)ErrorExit(__LINE__, SDL_GetError() ,__FILE__);
	if(0 == (img_init & IMG_INIT_JPG) )ErrorExit(__LINE__, SDL_GetError() ,__FILE__);
	if(0 == (img_init & IMG_INIT_PNG) )ErrorExit(__LINE__, SDL_GetError() ,__FILE__);
	if(0 == (img_init & IMG_INIT_TIF ))ErrorExit(__LINE__, SDL_GetError() ,__FILE__);

	//initialize();
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width,height ,0);
	
	if(window != nullptr){
		renderer = SDL_CreateRenderer(window,-1,0);
		if(renderer == nullptr){
			ErrorExit(__LINE__, SDL_GetError() ,__FILE__);	
		}
	}else{
		ErrorExit(__LINE__, SDL_GetError() ,__FILE__);	
	}
	

	srand(time(NULL));

	state = new State();
	Warning(__LINE__, "<<<<<<<<<<<<< alo >>>>>>>>>>>>>>>>" ,__FILE__);
		

}

void Game::initialize(){
	/*unsigned int img_init;

	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER))
		ErrorExit(__LINE__, SDL_GetError() ,__FILE__);

	img_init = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);

	if(img_init==false)
		ErrorExit(__LINE__, SDL_GetError() ,__FILE__);
	
	return;*/
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
	Warning(__LINE__, "<<<<<<<<<<<<< alo >>>>>>>>>>>>>>>>" ,__FILE__);

	//main loop
	while(state->QuitRequested()==false){
		/*pt 1 */
		
		/*pt 2 */
		Warning(__LINE__, "<<<<<<<<<<<<< alo >>>>>>>>>>>>>>>>" ,__FILE__);
		/*pt 3call update e render */
		state->Update();
		Warning(__LINE__, "aloo" ,__FILE__);

		state->Render();
		Warning(__LINE__, "aloo" ,__FILE__);exit(1);

		SDL_RenderPresent(renderer);//update screen
		
		/*		*		*		*		*		*		*		*		*		*
		 *Delay processor in 33 milisecound for the next frame(1 frame per 33ms)* 
		 *Should be around 30 FPS												*
		 * 		*		*		*		*		*		*		*		*		*/
		SDL_Delay(33); 
		
	}//end while main loop
	//Resources::ClearImages();
}

Game::~Game(){

	IMG_Quit();
	delete state;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	
}


