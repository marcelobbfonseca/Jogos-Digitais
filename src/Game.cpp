#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Resources.h"
#include "Game.h"
#include "error.h"
#include "InputManager.h"

using std::cout;
using std::string;

Game* Game::instance= nullptr;

Game::Game(string title, int width, int height) : inputManager(InputManager::GetInstance()){
	


	if(nullptr != instance ){
		ErrorExit(__LINE__, "Existe uma segunda instancia do jogo! " ,__FILE__);
	}else{
		instance = this;
	}

	if(0 != SDL_Init(SDL_INIT_VIDEO))//erro dando aqui!!!
		ErrorExit(__LINE__, SDL_GetError() ,__FILE__);

	//INITIALIZE IMAGES
	int img_init= IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);

	if(0 == img_init)ErrorExit(__LINE__, SDL_GetError() ,__FILE__);
	if(0 == (img_init & IMG_INIT_JPG) )ErrorExit(__LINE__, SDL_GetError() ,__FILE__);
	if(0 == (img_init & IMG_INIT_PNG) )ErrorExit(__LINE__, SDL_GetError() ,__FILE__);
	if(0 == (img_init & IMG_INIT_TIF ))ErrorExit(__LINE__, SDL_GetError() ,__FILE__);

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width,height ,0);
	
	if(window != nullptr){
		renderer = SDL_CreateRenderer(window,-1,0);
		if(renderer == nullptr){
			ErrorExit(__LINE__, SDL_GetError() ,__FILE__);	
		}
	}else{
		ErrorExit(__LINE__, SDL_GetError() ,__FILE__);	
	}
	
	//initialize Audios
	int mix_init = Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG); 
	
	if(mix_init==false)ErrorExit(__LINE__, Mix_GetError() ,__FILE__);	
	if( mix_init & MIX_INIT_OGG == 0)ErrorExit(__LINE__, Mix_GetError() ,__FILE__);	


	if(Mix_OpenAudio( MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT , MIX_DEFAULT_CHANNELS, 1024/*chuncksize*/ ) != 0)
		ErrorExit(__LINE__, Mix_GetError() ,__FILE__);	

	//initialize ttf
	if(0 != TTF_Init())
		ErrorExit(__LINE__, TTF_GetError() ,__FILE__);

	
	srand(time(NULL));
	//state = new StageState();
	storedState = nullptr;
	dt= 0.0;
	frameStart = 0;

}

Game& Game::GetInstance(){
	return *instance;
}
State& Game::GetCurrentState(){
	return *stateStack.top();
}

/*
StageState& Game::GetState(){
	return *state;
}
*/

SDL_Renderer* Game::GetRenderer(){
	return renderer;
}
void Game::Run(){
	if(storedState !=  nullptr){

		stateStack.push(std::unique_ptr<State>(storedState));
		storedState= nullptr;
	}
	else{
		return;//end game
	}

	while(!stateStack.empty()){


		if(stateStack.top()->QuitRequested())
			break;

		CalculateDeltaTime();
		inputManager.Update(); //GetDeltaTime()
		stateStack.top()->Update(dt);
		stateStack.top()->Render();
		SDL_RenderPresent(renderer);//update screen
		
		//UpdateStack
		if(stateStack.top()->PopRequested()){
			stateStack.pop();
			Resources::ClearImages();
			Resources::ClearMusic();
			
			if(!stateStack.empty())
				stateStack.top()->Resume();
			
		}

		if(storedState != nullptr){
			if(!stateStack.empty())
				stateStack.top()->Pause();
			
			stateStack.push(std::unique_ptr<State>(storedState));
			storedState= nullptr;
		}

		
		SDL_Delay(33); 
	}

	/*
	state->LoadAssets();

	while(state->QuitRequested()==false){
		CalculateDeltaTime();
		inputManager.Update();
		state->Update();
		state->Render();
		SDL_RenderPresent(renderer);//update screen
		SDL_Delay(33); 
	}//end while main loop
	Resources::ClearImages();*/
}


void Game::CalculateDeltaTime(){
	u_int32_t newTick;

	newTick = SDL_GetTicks();
	dt=(newTick- frameStart)/1000.0;
	dt = (float) dt;//converted to seconds
	frameStart= newTick;
}
float Game::GetDeltaTime(){
	return dt;
}

Game::~Game(){

	if(storedState != nullptr)
			delete storedState;

	IMG_Quit();
	//delete state;

	while(!stateStack.empty()){
		stateStack.pop();
	}
	TTF_Quit();
	Mix_CloseAudio();
	Mix_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	
}


void Game::Push(State* state){
	if(storedState != nullptr)
		cout << "Ue..." << std::endl;

	storedState= state;
}

SDL_Window* Game::GetWindow(){
	return window;
}