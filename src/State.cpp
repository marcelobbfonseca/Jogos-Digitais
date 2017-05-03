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


State::State() : tileSet(64, 64, "img/tileset.png"), inputManager(InputManager::GetInstance()){

    tileMap = new TileMap("map/tileMap.txt", &tileSet);
	quitRequested = false;
    //por em 512, 300
    objectArray.emplace_back(std::unique_ptr<Alien>( new Alien (512,300, 5) ));
}

void State::LoadAssets(){
 bg.Open("img/ocean.jpg");

}

void State::Update(){
    int mouseX, mouseY;
    if(inputManager.QuitRequested() or inputManager.KeyPress(ESCAPE_KEY))
        quitRequested=true;

    //if space key is pressed create face
    if(inputManager.KeyPress(ESPACE_KEY)){
        //SDL_GetMouseState(&mouseX, &mouseY);
        //AddObject(new Alien(0,0,0));
    }
    
    if(inputManager.isMouseDown(SDL_BUTTON_LEFT)) {
    /*    for(int i = objectArray.size() - 1; i >= 0; --i) {
            Face* face = (Face*) objectArray[i].get();
                face->Damage(rand() % 10 + 10);
                break;
          }
    */
    }
    

 	//checking if any object has died
	for(unsigned int i = 0; i < objectArray.size(); i++){
        printf("\t\t\tALOOO caiu: %d\n", i);
        objectArray.at(i)->Update(Game::GetInstance().GetDeltaTime());
        if(objectArray[i]->isDead()){
			objectArray.erase(objectArray.begin()+i);
		}

 	}//end for objArrayLoop
    
    Camera::Update(Game::GetInstance().GetDeltaTime());
}

void State::Render(){
	bg.Render(0, 0);
    cout << "(pos.x, pos.y): " << Camera::pos.x << ", " << Camera::pos.y << endl;
    tileMap->Render(Camera::pos.x, Camera::pos.y); 
	
    //render all objects .for loop
	for(unsigned int i = 0; i < objectArray.size(); i++)
		objectArray[i]->Render();

}
void State::AddObject(GameObject* ptr){
    //increment given gameobject to object array
    objectArray.emplace_back(std::unique_ptr<GameObject>(ptr) );
    //objectArray.emplace_back(std::unique_ptr<Face>( new Face(mouseX, mouseY) ) );
}

bool State::QuitRequested(){
	return quitRequested;
}

State::~State(){
	delete tileMap;
	objectArray.clear();
}
