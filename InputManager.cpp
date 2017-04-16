#include "InputManager.h"

InputManager::InputManager(){

}

void InputManager::Update(){}

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