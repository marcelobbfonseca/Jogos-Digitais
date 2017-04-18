#pragma once

#include "GameObject.h"
#include "Vec2.h"
#include "Game.h"
#define CAMERA_MOVE_SPEED 10;

class Camera
{
public:
	static void Follow(GameObject* newFocus);
	static void Unfollow();
	static void Update(float dt);
	static Vec2 pos;
	static Vec2 speed;

private:
	static GameObject* focus;
};