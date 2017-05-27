#include <iostream>
#include <string>
#include <vector>
#include <memory>
using std::cout;
using std::string;
#include "SDL2/SDL.h"
#include "GameObject.h"
#include "Face.h"
#include "StageState.h" 
#include "Camera.h"
#include "error.h"
#include "Alien.h"
#include "Penguins.h"
#include "Collision.h"
#include "EndState.h"

#define MUSIC_LOOP 8
typedef unsigned int uint;

StageState::StageState() : music("audio/stageState.ogg"), bg("img/ocean.jpg"), tileSet(64, 64, "img/tileset.png"), inputManager(InputManager::GetInstance()){

    tileMap = new TileMap("map/tileMap.txt", &tileSet);
	quitRequested = false;
    objectArray.emplace_back(std::unique_ptr<Alien>( new Alien (512,300, 5) ));
    objectArray.emplace_back(std::unique_ptr<Alien>( new Alien (412,700, 5) ));
    objectArray.push_back(std::unique_ptr<Penguins>( new Penguins (704,640) ) );
    music.Play(8);
}

void StageState::Update(float dt){
    
    if(inputManager.KeyPress(ESCAPE_KEY))
        popRequested= true;
    
    if(inputManager.QuitRequested())
        quitRequested=true;
    
 	//Game objects update loop
	UpdateArray(dt);
    
    //collision detection
    for(uint i = 0; i < objectArray.size(); i++){
        for (uint j = i+1; j < objectArray.size(); j++){
            if(Collision::IsColliding(objectArray[i]->box, objectArray[j]->box, objectArray[i]->rotation, objectArray[j]->rotation)){
                objectArray[i]->NotifyCollision(*objectArray[j]);
                objectArray[j]->NotifyCollision(*objectArray[i]);
            }
        }
    }
    Camera::Update(Game::GetInstance().GetDeltaTime());

    //condiçao de vitoria/derrota
    if (Alien::alienCount == 0){ //win
        printf("YOU WINNNN CAIUUUU!!\n");
        popRequested= true;
        Game::GetInstance().Push(new EndState(StateData(true)));
    }
    if(Penguins::player == nullptr){ //lose
        printf("YOU LOOSE CAIUUUU!!\n");
        popRequested= true;
        Game::GetInstance().Push(new EndState(StateData(false)));
    }
}

void StageState::Render(){
	bg.Render(0, 0);
    tileMap->Render(Camera::pos.x, Camera::pos.y); 
	
    //render all objects .for loop
	for(unsigned int i = 0; i < objectArray.size(); i++)
		objectArray[i]->Render();

}

StageState::~StageState(){
	delete tileMap;

}

void StageState::Pause(){

}

void StageState::Resume(){

}
