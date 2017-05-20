#include "TitleState.h"
#include "InputManager.h"
#include "Game.h"
#include "StageState.h"

TitleState::TitleState():State(), bg("img/title.jpg"){

}
TitleState::~TitleState(){
	
}

void TitleState::Update(float dt){
	InputManager &inputManager = InputManager::GetInstance();

	if(inputManager.KeyPress(ESPACE_KEY)){
		Game::GetInstance().Push(new StageState());
	}
	else if(inputManager.QuitRequested()){
		quitRequested= true;
	}else if( inputManager.KeyPress(ESCAPE_KEY)){
		popRequested= true;
	}
}


void TitleState::Render(){
	bg.Render(0, 0);

}
void TitleState::Pause(void){

}
void TitleState::Resume(void){

}