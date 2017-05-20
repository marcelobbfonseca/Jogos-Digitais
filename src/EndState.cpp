#include "EndState.h"

EndState::EndState(StateData stateData): 
	bg((stateData.playerVictory)?"img/win.jpg":"img/lose.jpg"),
	music((stateData.playerVictory)?"audio/endStateWin.ogg": "audio/endStateLose.ogg"),
	instruction("font/Call me maybe.ttf",40 /*font size*/,BLENDED,((stateData.playerVictory)?"You Win!":"You Lose!") ,{255, 255, 255, 255}) 
{

	music.Play(0/*play once*/);
	instruction.SetText("Press Esc to go to menu or Space to play again!");

	bg.Render(0, 0);

	if (stateData.playerVictory){ //Win
		
	}else{ //Lose

	}

}
EndState::~EndState(){
	//delete bg;
	//delete music;
}
void EndState::Update(float dt){
	
}
void EndState::Render(){
	
}
void EndState::Pause(){
	
}
void EndState::Resume(){
	
}