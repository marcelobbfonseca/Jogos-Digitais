#include "Camera.h"
#include "InputManager.h"
#include "error.h"
#include "SDL2/SDL.h"
using std::cout;
using std::string;

GameObject* Camera::focus= nullptr;
Vec2 Camera::pos;
Vec2 Camera::speed;

#define FOCUS_X_PENGUIN_OFFSET 352 
#define FOCUS_Y_PENGUIN_OFFSET 320

void Camera::Follow(GameObject* newFocus){
	focus = newFocus;
}

void Camera::Unfollow(){
	focus= nullptr;
}
void Camera::Update(float dt){
	if(focus){
		pos = focus->box.Center() - Vec2(FOCUS_X_PENGUIN_OFFSET ,FOCUS_Y_PENGUIN_OFFSET);

	}else{ 
		if(InputManager::GetInstance().KeyPress(SDLK_LEFT) || InputManager::GetInstance().KeyPress('a')){
			
			pos.x = pos.x - (CAMERA_MOVE_SPEED * dt);
		}
		if(InputManager::GetInstance().KeyPress(RIGHT_ARROW_KEY) || InputManager::GetInstance().KeyPress('d')){

			pos.x = pos.x + (CAMERA_MOVE_SPEED * dt);
			cout <<pos.x << endl;
		}
		if(InputManager::GetInstance().KeyPress(UP_ARROW_KEY) || InputManager::GetInstance().KeyPress('w')){

			pos.y = pos.y - (CAMERA_MOVE_SPEED * dt);
		}
		if(InputManager::GetInstance().KeyPress(DOWN_ARROW_KEY) || InputManager::GetInstance().KeyPress('s')){

			pos.y = pos.y + (CAMERA_MOVE_SPEED * dt);
		}
	}//end else
}//end Camera::Update
