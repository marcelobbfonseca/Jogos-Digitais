#include "Minion.h"
#include "Bullet.h"
#include "error.h"
#include "Collision.h"
#include <cmath>

//in radians
#define MINION_CONST_SPEED 0.06
//Bullet speed and max distance
#define BULLET_SPEED 350
#define MAX_DISTANCE 600
//Used to turn minion back to Alien
#define MINION_ROTATION_OFFSET 1.383 
//used for minion distance to Alien
#define MINION_DISTANCE 100
//used to sort random minion size
#define MINION_SIZE_HI 1.5
#define MINION_SIZE_LO 1.0

#define MINION_BULLET_LO 150.0
#define MINION_BULLET_HI 550.0


#define MINION_BULLET_SPRITES 3
#define MINION_BULLET_SPRITE_TIME 0.05

Minion::Minion(GameObject* minionCenter, float arcOffset): sp("img/minion.png"){
	arc = arcOffset;
	this->center = minionCenter;
	
	//random generate a float between 1.0 and 1.5 for minion size(scale)
	float minionScale = MINION_SIZE_LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(MINION_SIZE_HI-MINION_SIZE_LO)));
	sp.SetScaleX(minionScale);
	sp.SetScaleY(minionScale);

	//calcular valor da box
	box.w = sp.GetWidth();
	box.h = sp.GetHeight();
	box = center->box.Center() - Vec2(sp.GetWidth()/2, sp.GetHeight()/2);
	

}
void Minion::Update(float dt){

	arc = (arc + MINION_CONST_SPEED); // dt *
	
	Vec2 distToAlien= Vec2(MINION_DISTANCE, 0).Rotate(arc);
	Vec2 novaCoord= center->box.Center() + distToAlien;

	//box
	box = novaCoord - Vec2(sp.GetWidth()/2, sp.GetHeight()/2);
	//calculate new rotation
	rotation = MINION_ROTATION_OFFSET+arc;
	
}
void Minion::Render(){
	sp.Render(box.x-Camera::pos.x, box.y-Camera::pos.y, rotation);
}

bool Minion::isDead(){
	return false;
}
void Minion::Shoot(Vec2 pos){
	float xNew,yNew, angle;
	float bulletSpeed = MINION_BULLET_LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(MINION_BULLET_HI-MINION_BULLET_LO)));
	

	Vec2 PosNew = pos-box;
	angle = PosNew.InclineVet();

	xNew = box.x-Camera::pos.x + sp.GetWidth()/2;
	yNew = box.y-Camera::pos.y + sp.GetHeight()/2; 

	Bullet* bullet= new Bullet(xNew,yNew,angle,bulletSpeed,MAX_DISTANCE,"img/minionbullet2.png", 0.05/*MINION_BULLET_SPRITE_TIME*/, MINION_BULLET_SPRITES, true);
	Game::GetInstance().GetCurrentState().AddObject(bullet);

}


bool Minion::Is(string type){
	return type == "Minion";
}
void Minion::NotifyCollision(GameObject& other){
	if (other.Is("Bullet")){
		if(((Bullet&)other).GetTargetsPlayer()){
			printf("ouch!\n");
		}
	}
}

Minion::~Minion(){

}
