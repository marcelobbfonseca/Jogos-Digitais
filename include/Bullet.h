#pragma once
#include <iostream>
#include <string>

#include "GameObject.h"
#include "Vec2.h"
#include "Sprite.h"
#include "Camera.h"

class Bullet : public GameObject
{
public:
	Bullet(float x, float y, float angle, float speed, float maxDistance, std::string sprite, float frameTime, int frameCount, bool targetsPlayer);
	void Update(float dt);
	void Render();
	bool isDead();
	
	bool Is(string type);
	void NotifyCollision(GameObject& other);
	bool GetTargetsPlayer();
	~Bullet();
private:
	Sprite sp;
	Vec2 speed;
	float angle;//bullet angle inclination
	float distanceLeft;
	bool targetsPlayer;
};