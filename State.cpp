#include <iostream>
#include <string>
using namespace std;

#include "State.h"

//duvida instaciar
State::State(){
	//e instancia sprite. chamar o constr de sprite
	quitRequested = false;

}
State::~State(){

}

void State::LoadAssets(){
 // "Recursos/img/ocean.jpg"
}

void State::Update(float dt){
 	//click X or alt+f4
 	if(SDL_QuitRequested())
 		quitRequested = true;
}

//duvida rend
void State::Render(){
//renderizar bg
}

bool State::QuitRequested(){
	return quitRequested;
}