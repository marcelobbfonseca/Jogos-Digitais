#include <iostream>
#include <string>
using namespace std;

#include "State.h"

State::State(){
	//instanciar sprite
	bg = new Sprite();
	quitRequested = false;

}

void State::LoadAssets(){
 bg.Open("img/ocean.jpg");
}

void State::Update(){
 	Input();
 	//checking if any face has died
	for(int i = 0; i < objectArray.size();i++){

		if((Face *)objectArray[i]->isDead()){
			iterator it = objectArray.begin() + i;
			objectArray.erase(it);
		}


 	}//end for objArrayLoop

}

void State::Render(){
	bg.Render(0, 0);
	//percorre array chamando render de todos os objetos .for
	for(int i = 0; i < objectArray.size(); i++)
		objectArray[i].Render();

}
void State::AddObject(int mouseX, int mouseY){

	Face *face = new Face(mouseX,mouseY);

}

bool State::QuitRequested(){
	return quitRequested;
}

void State::Input(){
	/*O   corpo   dessa   função   está   disponível   no   Moodle.   Podem   ser  
necessários   alguns   ajustes   nele   para   se   adequar   aos   nomes   de   variáveis   ou  
funções   do   seu   código.   Além   disso,   você   pode   tirar   a   chamada   à  
SDL_QuitRequested   em   Update(),   já   que   Input   cuida   de   eventos   de  
SDL_QUIT para nós. */
    SDL_Event event;
    int mouseX, mouseY;

    // Obtenha as coordenadas do mouse
    SDL_GetMouseState(&mouseX, &mouseY);

    // SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
    while (SDL_PollEvent(&event)) {

	 	//click X or alt+f4 for quit condition
        if(SDL_QuitRequested())
 			quitRequested = true;
        
        // Se o evento for clique...
        if(event.type == SDL_MOUSEBUTTONDOWN) {

            // Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
            for(int i = objectArray.size() - 1; i >= 0; --i) {
                // Obtem o ponteiro e casta pra Face.
                Face* face = (Face*) objectArray[i].get();
                // WARNING: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
                // O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
                // ao usar get(), violamos esse princípio e estamos menos seguros.
                // Esse código, assim como a classe Face, é provisório. Futuramente, para
                // chamar funções de GameObjects, usaremos objectArray[i]->função() direto.

                if(face->box.IsInside((float)mouseX, (float)mouseY)) {
                    // Aplica dano
                    face->Damage(rand() % 10 + 10);
                    // Sai do loop (só queremos acertar um)
                    break;
                }
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
	delete bg;
	objectArray.clear();
}
