#pragma once

#include "GameObject.h"
#include "Vec2.h"
#define CAMERA_MOVE_SPEED 10;

class Camera
{
public:
	Camera();
	static void Follow(GameObject* newFocus);
	static void Unfollow();
	static void Update(float dt);
	~Camera();
	static Vec2 pos;
	static Vec2 speed;

private:
	static GameObject* focus;
};