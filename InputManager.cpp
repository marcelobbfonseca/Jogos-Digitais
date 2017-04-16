#include "InputManager.h"
#include "SDL2/SDL.h"
#include "error.h"
#define MOUSE_ARRAY_LENGHT 6
#define KEY_LENGHT 416


InputManager::InputManager(){


	quitRequested=false;
	updateCounter=0;
	mouseX=0; 
	mouseY=0;
	for (int i = 0; i < MOUSE_ARRAY_LENGHT; ++i){
		mouseState[i] = false;
		mouseUpdate[i] = 0;
	}
	for (int i = 0; i < KEY_LENGHT; ++i){
		keyState[i]=false;
		keyUpdate[i]=0;
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
	 			mouseState[event.button.button] = false;
	 			break;

	 		case SDL_KEYDOWN:
				keyState[event.key.keysym.sym] = true;
				keyUpdate[event.key.keysym.sym] = updateCounter;
	 			break;

	 		case SDL_KEYUP:
				keyState[event.key.keysym.sym] = false;
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
	
int InputManager::GetMouseX(){
	return mouseX;
}
int InputManager::GetMouseY(){
	return mouseY;
}
bool InputManager::QuitRequested(){
	return quitRequested;
}

InputManager& InputManager::GetInstance(){
	static InputManager i;
	return i;
}

InputManager::~InputManager(){
	
}