
#include "State.h"
#include "Collision.h"

//#include "Game.h"

#include <iostream>
using std::cout;
using std::string;
typedef unsigned int uint;


State::State(){
	popRequested=false; 
	quitRequested=false;
}


State::~State(){

}

void State::AddObject(GameObject* ptr){
    //increment given gameobject to object array
    objectArray.emplace_back(std::unique_ptr<GameObject>(ptr) );
}

bool State::QuitRequested(){
	return quitRequested;
}
bool State::PopRequested(){
	return popRequested;
}


void State::RenderArray(float dt){
    //render all objects .for loop
	for(uint i = 0; i < objectArray.size(); i++)
		objectArray[i]->Render();

}

void State::UpdateArray(float dt){

	for(uint i = 0; i < objectArray.size(); i++){
        objectArray.at(i)->Update(dt);
        
        //death detection
        if(objectArray[i]->isDead()){
            objectArray.erase(objectArray.begin()+i);
        }

 	}//end for objArrayLoop
}