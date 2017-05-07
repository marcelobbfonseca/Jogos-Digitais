#include "Penguins.h"
#include "InputManager.h"
#include "Camera.h"

Penguins* Penguins::player = nullptr;

Penguins::Penguins(float x, float y): speed(){
	bodySp.Open("img/penguin.png");
	cannonSp.Open("img/cubngun.png");

	box.x = x; //- bodySp.GetWidth()/2; 
	box.y = y; // - bodySp.GetHeight()/2;
	box.w = bodySp.GetWidth();
	box.h = bodySp.GetHeight();
	

	player = this;
	linearSpeed = PENGUIN_SPEED;
	cannonAngle = 1.0;
	hp = PENGUIN_HEALTH;
	//Camera::Follow(this);


}
void Penguins::Update(float dt){
	InputManager &i= InputManager::GetInstance();

	if(i.IsKeyDown('w') || i.IsKeyDown('W')){
		
		if(speed.Magnitude() <= MAX_SPEED)
			speed = Vec2(XCONST,YCONST) + speed+speed;// linearSpeed+PENGUIN_ACCELERATION*dt;
		
	}
	else if(i.IsKeyDown('s') || i.IsKeyDown('S')){
		if(speed.Magnitude() <= MAX_SPEED)
			speed = Vec2(XCONST,YCONST) + speed+speed;//linearSpeed+speed *PENGUIN_ACCELERATION*dt;
	
	}
	if(i.IsKeyDown('a') || i.IsKeyDown('A')){
		rotation -= PENGUIN_ANG_SPEED * dt;
	}
	else if(i.IsKeyDown('d') || i.IsKeyDown('D')){
		rotation += PENGUIN_ANG_SPEED * dt;
	
	}

}	
void  Penguins::Render(){
	bodySp.Render(box.x-Camera::pos.x, box.y-Camera::pos.y, rotation);
	cannonSp.Render(box.x-Camera::pos.x, box.y-Camera::pos.y, cannonAngle);
}

bool Penguins::isDead(){
	if(hp<=0)
		return true;
	else
		return false;
}
void Penguins::Shoot(){

}

Penguins::~Penguins(){
	player = nullptr;
	//Camera::Unfollow();
}
