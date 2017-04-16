#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

#include "SDL2/SDL.h"
#include "GameObject.h"
#include "Face.h"
#include "State.h" 
#include "error.h"
State::State() : tileSet(64, 64, "img/tileset.png"){

    tileMap = new TileMap("map/tileMap.txt", &tileSet);
	quitRequested = false;

}

void State::LoadAssets(){
 bg.Open("img/ocean.jpg");

}

void State::Update(){
        
 	Input();

 	//checking if any face has died
	for(int i = 0; i < objectArray.size(); i++){

		if(objectArray[i]->isDead()){

			objectArray.erase(objectArray.begin()+i); // if fails try using: .at(i)
		}

 	}//end for objArrayLoop

}

void State::Render(){
	bg.Render(0, 0);

    tileMap->Render(); // 0 because we still dont have a camera
	
    //render all objects .for loop
	for(int i = 0; i < objectArray.size(); i++)
		objectArray[i]->Render();

}
void State::AddObject(int mouseX, int mouseY){

    objectArray.emplace_back(std::unique_ptr<Face>( new Face(mouseX, mouseY) ) );
}

bool State::QuitRequested(){
	return quitRequested;
}

void State::Input(){

    SDL_Event event;
    int mouseX, mouseY;


    // Obtenha as coordenadas do mouse
    SDL_GetMouseState(&mouseX, &mouseY);

    // SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
    while (SDL_PollEvent(&event)) {

	 	//click X or alt+f4 for quit condition
        if(event.type == SDL_QUIT) 
            quitRequested = true;

        // Se o evento for clique...
        if(event.type == SDL_MOUSEBUTTONDOWN) {

            // Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
            for(int i = objectArray.size() - 1; i >= 0; --i) {
                // Obtem o ponteiro e casta pra Face.
                Face* face = (Face*) objectArray[i].get();
                //if(face->box.IsInside((float)mouseX, (float)mouseY)) {
                    // Apply damage
                    face->Damage(rand() % 10 + 10);
                    // Sai do loop (só queremos acertar um)
                    break;
                //}
            }
        }

        if( event.type == SDL_KEYDOWN ) {
            // Se a tecla for ESC, setar a flag de quit
            if( event.key.keysym.sym == SDLK_ESCAPE ) {
                quitRequested = true;
            }
            // Se não, crie um objeto
            else {
                AddObject((float)mouseX, (float)mouseY);
            }
        }
    }//end while PoolEvent
    return;
}//end State::Input

State::~State(){
	delete tileMap;
	objectArray.clear();
}
