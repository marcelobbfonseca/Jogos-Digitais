#include "Bullet.h"
#include "error.h"

#define BULLET_SPEED 0.5

Bullet::Bullet(float x, float y, float angle, float speed, float maxDistance, std::string sprite): sp("img/minionbullet1.png"){
	box.x = Camera::pos.x + x - sp.GetWidth()/2;
	box.y = Camera::pos.y + y - sp.GetHeight()/2;
	box.w = sp.GetWidth();
	box.h = sp.GetHeight();
	
	this->speed = Vec2(x,y).Rotate(angle);
	distanceLeft = maxDistance;
}

void Bullet::Update(float dt){
 	box = box + (speed * dt);
 	distanceLeft -= speed.Magnitude() * dt;
}

void Bullet::Render(){
	sp.Render(box.x - Camera::pos.x, box.y - Camera::pos.y, 0);
}

bool Bullet::isDead(){
	if (distanceLeft<=0.0)
		return true;
	else
		return false;
}

Bullet::~Bullet(){

}