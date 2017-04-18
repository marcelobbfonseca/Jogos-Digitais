#include "Camera.h"
#include "InputManager.h"
#include "error.h"
#include "SDL2/SDL.h"
using namespace std;

GameObject* Camera::focus= nullptr;
Vec2 Camera::pos;
Vec2 Camera::speed;


void Camera::Follow(GameObject* newFocus){
	focus = newFocus;
}

void Camera::Unfollow(){
	focus= nullptr;
}
void Camera::Update(float dt){
	if(focus){

	}else{ 
		debugInt("VALOR LEFT_ARROW_KEY: ", LEFT_ARROW_KEY, __FILE__, __LINE__ );
		if(InputManager::GetInstance().KeyPress(SDLK_LEFT) || InputManager::GetInstance().KeyPress('d')){
			
			pos.x = pos.x - CAMERA_MOVE_SPEED;
			//pos.x = (float)pos.x * dt;

			if(pos.x < 0){
				pos.x = 0;
			}
			//cout <<pos.x << endl;
		}
		if(InputManager::GetInstance().KeyPress(RIGHT_ARROW_KEY) || InputManager::GetInstance().KeyPress('d')){

			pos.x = pos.x + CAMERA_MOVE_SPEED;
			//cout <<pos.x << endl;
		}
		if(InputManager::GetInstance().KeyPress(UP_ARROW_KEY) || InputManager::GetInstance().KeyPress('w')){

			pos.y = pos.y - CAMERA_MOVE_SPEED;

			if(pos.y < 0){
				pos.y = 0;
			}
			//cout << pos.y << endl;
		}
		if(InputManager::GetInstance().KeyPress(DOWN_ARROW_KEY) || InputManager::GetInstance().KeyPress('s')){

			pos.y = pos.y + CAMERA_MOVE_SPEED;
			//cout << pos.y << endl;
		}
	}//end else
}//end Camera::Update
