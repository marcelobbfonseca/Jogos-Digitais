#include "InputManager.h"
#include "SDL2/SDL.h"
#include "error.h"
#define MOUSE_ARRAY_LENGHT 6



InputManager::InputManager(){


	quitRequested=false;
	updateCounter=0;
	mouseX=0; 
	mouseY=0;
	for (int i = 0; i < MOUSE_ARRAY_LENGHT; ++i){
		mouseState[i] = false;
		mouseUpdate[i] = 0;
	}

}

void InputManager::Update(){
	SDL_Event event;
	++updateCounter;

    while (SDL_PollEvent(&event)) {
	 	
	 	if(event.key.repeat)
	 		continue;

	 	switch(event.type){
	 		case SDL_QUIT:	
	 			quitRequested = true;
	 			break;

	 		case SDL_MOUSEBUTTONDOWN:
	 			mouseState[event.button.button] = true;
	 			mouseUpdate[event.button.button] =updateCounter;
	 			break;
	 	
	 		case SDL_MOUSEBUTTONUP:
	 			mouseState[event.button.button] = true;
	 			mouseUpdate[event.button.button] =updateCounter;
	 			break;

	 		case SDL_KEYDOWN:

	 			break;

	 		case SDL_KEYUP:

	 			break;

	 		default:break;
	 	}


    }//end::while PollEvent
   

}

bool InputManager::Keypress(int key){return false;}
bool InputManager::KeyRelease(int key){return false;}
bool InputManager::IsKeyDown(int key){return false;}
	
bool InputManager::MousePress(int button){return false;}
bool InputManager::MouseRelease(int button){return false;}
bool InputManager::isMouseDown(int button){return false;}
	
int InputManager::GetMouseX(){return 0;}
int InputManager::GetMouseY(){return 0;}

bool InputManager::QuitRequested(){return false;}

InputManager& InputManager::GetInstance(){
	static InputManager i;
	return i;
}

InputManager::~InputManager(){
	
}