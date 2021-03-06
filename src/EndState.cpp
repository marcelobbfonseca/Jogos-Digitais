#include "EndState.h"
#include "InputManager.h"
#include "Game.h"
EndState::EndState(StateData stateData): State(),
	bg((stateData.playerVictory)?"img/win.jpg":"img/lose.jpg"),
	music((stateData.playerVictory)?"audio/endStateWin.ogg": "audio/endStateLose.ogg"),
	instruction("font/Call me maybe.ttf",40 /*font size*/,BLENDED,((stateData.playerVictory)?"You Win!":"You Lose!") ,{255, 255, 255, 255}) 
{

	instruction.SetText("Press ESC to exit or SPACE to play!");
 
	if (stateData.playerVictory){ //Win
		//bg.Open("img/win.jpg");
	
	}else{ //Lose
		//bg.Open("img/lose.jpg");

	}
	music.Play(0/*play once*/);

}
EndState::~EndState(){
	//delete bg;
	//delete music;
}
void EndState::Update(float dt){
	InputManager &inputManager = InputManager::GetInstance();
	Game &game = Game::GetInstance();

	if(inputManager.QuitRequested()){ //esc
		quitRequested=true;
    }
    if(inputManager.KeyPress(ESCAPE_KEY)){
		popRequested=true;
	}
	if(inputManager.KeyPress(ESPACE_KEY)){
		popRequested=true;
		game.Push(new StageState());
	}


}
void EndState::Render(){
	bg.Render(0, 0);
}
void EndState::Pause(){
	
}
void EndState::Resume(){
	
}