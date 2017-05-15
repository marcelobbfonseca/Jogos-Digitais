#ifndef PENGUIN_H
#define PENGUIN_H

#include "Sprite.h"
#include "GameObject.h"
#include "Vec2.h"

#define PENGUIN_HEALTH 100
#define PENGUIN_SPEED 50.0
#define PENGUIN_ANG_SPEED 0.5
#define MAX_SPEED 300.0
#define PENGUIN_ACCELERATION 3.2

#define XCONST 1
#define YCONST 0

class Penguins : public GameObject
{
public:
	Penguins(float x, float y);
	~Penguins();
	
	void Update(float dt);
	void Render();
	bool isDead();
	void Shoot();
	
	bool Is(string type);
	void NotifyCollision(GameObject& other);

	static Penguins* player;
private:
	Sprite bodySp;
	Sprite cannonSp;
	Vec2 speed;
	float linearSpeed, cannonAngle;
	int hp;
};

#endif