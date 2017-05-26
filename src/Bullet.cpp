#include "Bullet.h"
#include "error.h"
#include "Collision.h"



using std::string;
Bullet::Bullet( float x, float y, 
				float angle, float speed, 
				float maxDistance, std::string sprite, 
				float frameTime, int frameCount , bool targetsPlayer): GameObject(), sp(sprite, frameCount, frameTime){

	box.x = Camera::pos.x + x - sp.GetWidth()/2;
	box.y = Camera::pos.y + y - sp.GetHeight()/2;
	box.w = sp.GetWidth();
	box.h = sp.GetHeight();
	this->angle = angle;
	this->speed = Vec2(speed, 0).Rotate(angle);
	distanceLeft = maxDistance;
	this->targetsPlayer = targetsPlayer;
}

void Bullet::Update(float dt){
 	box = box + (speed * dt);
 	distanceLeft -= speed.Magnitude() * dt;
 	sp.Update(dt);
}

void Bullet::Render(){
	sp.Render(box.x - Camera::pos.x, box.y - Camera::pos.y, angle);
}

bool Bullet::isDead(){
	if (distanceLeft<=0.0)
		return true;
	else
		return false;
}

bool Bullet::Is(string type){
	return type == "Bullet";
}


void Bullet::NotifyCollision(GameObject& other){
	if (other.Is("Bullet")){
		return;
	} 
	else if( (other.Is("Minion") and targetsPlayer==false) or ((other.Is("Alien") and targetsPlayer==false)) or (other.Is("Penguins") and targetsPlayer) ){
		distanceLeft= 0;
		return;
	}
}

bool Bullet::GetTargetsPlayer(){
	return targetsPlayer;
}

Bullet::~Bullet(){

}