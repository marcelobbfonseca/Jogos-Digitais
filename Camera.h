#pragma once

#include "GameObject.h"

class Camera
{
public:
	Camera();
	static void Follow(GameObject* newFocus);
	static void Unfollow();
	static void Update(float dt);
	~Camera();
private:
	static Vec2 pos;
	static Vec2 speed;
	static GameObject* focus;
};