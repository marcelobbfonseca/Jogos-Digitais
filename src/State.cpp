#include <iostream>
#include <string>
#include <vector>
#include <memory>
using std::cout;
using std::string;
#include "SDL2/SDL.h"
#include "GameObject.h"
#include "Face.h"
#include "State.h" 
#include "Camera.h"
#include "error.h"
#include "Alien.h"
#include "Penguins.h"

State::State() : tileSet(64, 64, "img/tileset.png"), inputManager(InputManager::GetInstance()){

    tileMap = new TileMap("map/tileMap.txt", &tileSet);
	quitRequested = false;
    objectArray.emplace_back(std::unique_ptr<Alien>( new Alien (512,300, 5) ));
    objectArray.push_back(std::unique_ptr<Penguins>( new Penguins (300,300) ) );

}

void State::LoadAssets(){
 bg.Open("img/ocean.jpg");

}

void State::Update(){
    if(inputManager.QuitRequested() or inputManager.KeyPress(ESCAPE_KEY))
        quitRequested=true;

    
 	//checking if any object has died
	for(unsigned int i = 0; i < objectArray.size(); i++){
        objectArray.at(i)->Update(Game::GetInstance().GetDeltaTime());
        if(objectArray[i]->isDead()){
			objectArray.erase(objectArray.begin()+i);
		}

 	}//end for objArrayLoop
    
    Camera::Update(Game::GetInstance().GetDeltaTime());
}

void State::Render(){
	bg.Render(0, 0);
    tileMap->Render(Camera::pos.x, Camera::pos.y); 
	
    //render all objects .for loop
	for(unsigned int i = 0; i < objectArray.size(); i++)
		objectArray[i]->Render();

}
void State::AddObject(GameObject* ptr){
    //increment given gameobject to object array
    objectArray.emplace_back(std::unique_ptr<GameObject>(ptr) );
}

bool State::QuitRequested(){
	return quitRequested;
}

State::~State(){
	delete tileMap;
	objectArray.clear();
}
