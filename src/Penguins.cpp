#include "Penguins.h"

Penguins::Penguins(float x, float y){
	bodySp.Open("img/penguin.png");
	cannonSp.Open("img/cubngun.png");
	box.x = x - cannonSp.GetWidth()/2; 
	box.y = y - cannonSp.GetHeight()/2;
	box.w = cannonSp.GetWidth();
	box.h = cannonSp.GetHeight();
	linearSpeed = PENGUIN_SPEED;
	cannonAngle = 1;
	hp = PENGUIN_HEALTH;
}
void Penguins::Update(float dt){}	
bool Penguins::isDead(){return false;}
void Penguins::Shoot(){}

Penguins::~Penguins(){}
