#include "Penguins.h"
#include "InputManager.h"
#include "Camera.h"
#include "Collision.h"
#include "Bullet.h"
#include "Animation.h"
#include "Sound.h"

#define PENGUIN_BULLET_SPEED 200.0
#define PENGUIN_BULLET_MAX_DISTANCE 540
#define PENGUIN_DMG 30

#define PENGUIN_BULLET_SPRITES 4
#define PENGUIN_BULLET_SPRITE_TIME 0.66
#define CONST 0.25

using std::string;

Penguins* Penguins::player = nullptr;

Penguins::Penguins(float x, float y): bodySp("img/penguin.png"), cannonSp("img/cubngun.png"), GameObject(), speed(){
	//bodySp.Open("img/penguin.png");
	//cannonSp.Open("img/cubngun.png");

	box.x = x; //- bodySp.GetWidth()/2; 
	box.y = y; // - bodySp.GetHeight()/2;
	box.w = bodySp.GetWidth();
	box.h = bodySp.GetHeight();
	


	player = this;
	linearSpeed = PENGUIN_SPEED;
	cannonAngle = 1.0;
	hp = PENGUIN_HEALTH;
	Camera::Follow(this);


}
void Penguins::Update(float dt){
	InputManager &i= InputManager::GetInstance();

	

	// up and down
	if(i.IsKeyDown('w') or i.IsKeyDown('W')){
		
		if(speed.x >= MAX_SPEED ){
			speed= Vec2(MAX_SPEED,0.0);
		}else{
			speed.x = speed.x + CONST + PENGUIN_ACCELERATION;
		}
		//printf("GO!! %f\n", speed.x);
		
	}
	else if(i.IsKeyDown('s') or i.IsKeyDown('S')){
		
		if(speed.x <= 0.0)
			speed= Vec2(0.0,0.0);
		else
			speed.x = speed.x - (10*CONST) - PENGUIN_ACCELERATION * dt;
		
		//printf("BREAK!! %f\n", speed.x);
	
	}

	//left or right
	if(i.IsKeyDown('a') or i.IsKeyDown('A')){
		rotation = rotation - CONST - PENGUIN_ANG_SPEED * dt;

	}
	if(i.IsKeyDown('d') or i.IsKeyDown('D')){
		rotation = rotation + CONST + PENGUIN_ANG_SPEED * dt;

	}


	box= box + speed.Rotate(rotation)*dt;
	float x = i.GetMouseX();
	float y = i.GetMouseY();
	cannonAngle= (Vec2(x,y) - (box.Center()-Camera::pos)).InclineVet();
	
	if(i.MousePress(LEFT_MOUSE_BUTTON))
		Shoot();

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

	float xNew = box.x - Camera::pos.x + cannonSp.GetWidth()/2;
	float yNew = box.y - Camera::pos.y + cannonSp.GetHeight()/2;

	Bullet* bullet = new Bullet(xNew, yNew, cannonAngle,
								PENGUIN_BULLET_SPEED, PENGUIN_BULLET_MAX_DISTANCE, 
								"img/penguinbullet.png", PENGUIN_BULLET_SPRITE_TIME, 
								PENGUIN_BULLET_SPRITES, false
								); //PENGUIN_BULLET_SPRITES
	Game::GetInstance().GetCurrentState().AddObject(bullet);
}

bool Penguins::Is(string type){
	return type == "Penguins";
	//return (Penguins::Is(type)|| type == "Penguins");
}
void Penguins::NotifyCollision(GameObject& other){
	if (other.Is("Bullet")){
		if(((Bullet&)other).GetTargetsPlayer()){
			hp = hp - PENGUIN_DMG;
			printf("(%d)IM HIT!! !!\n", hp);
			if(isDead()){
				printf("Dear diary, today i died.\n");
				Sound deathSound("audio/boom.wav");
				deathSound.Play(0/*play once*/); 
				Game::GetInstance().GetCurrentState().AddObject( new Animation(box.x, box.y, rotation, "img/penguindeath.png", 5, 0.3, true));
				Camera::Unfollow();
			}
		}
	}
}



Penguins::~Penguins(){
	
	player = nullptr;

}
