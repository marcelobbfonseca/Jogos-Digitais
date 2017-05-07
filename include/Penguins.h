#ifndef PENGUIN_H
#define PENGUIN_H

#include "Sprite.h"
#include "GameObject.h"

#define PENGUIN_HEALTH 30
#define PENGUIN_SPEED 80

class Penguins : public GameObject
{
public:
	Penguins(float x, float y);
	~Penguins();
	
	void Update(float dt);
	bool isDead();
	void Shoot();
	Penguins* player;
private:
	Sprite bodySp;
	Sprite cannonSp;
	float linearSpeed, cannonAngle;
	int hp;
};

#endif