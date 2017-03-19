#include <iostream>
#include <string>
using namespace std;

#include "State.h"
#include "Game.h"

State::State(){
	//inicializa quitrequested e instancia sprite

}


void State::LoadAssets(){

}

void State::Update(float dt){
 	//click X or alt+f4
 	if(SDL_QuitRequested())
 		quitRequested = true;
}


void State::Render(){
//renderizar bg
}

bool State::QuitRequested(){
	return quitRequested;
}