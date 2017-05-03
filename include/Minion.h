#pragma once

#include "GameObject.h"
#include "Vec2.h"
#include "Sprite.h"
#include "Camera.h"



class Minion : public GameObject
{
public:
	Minion(GameObject* minionCenter, float arcOffset=0);
	void Update(float dt);
	void Render();
	bool isDead();
	void Shoot(Vec2 pos);
	~Minion();
private:
	Sprite sp;
	GameObject* center;
	float arc;

};