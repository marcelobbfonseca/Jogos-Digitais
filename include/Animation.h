#ifndef ANIMATION_H
#define ANIMATION_H

#include "Sprite.h"
#include "Timer.h"
#include "GameObject.h"

using std::string;
class Animation : public GameObject
{
public:
	Animation(float x, float y, float rotation, string sprite, int frameCount, float frameTime, bool ends);
	~Animation();
	
	void Update(float dt);
	void Render();
	bool isDead();

	void NotifyCollision(GameObject* other);
	bool Is(string type);

private:
	Timer endTimer;
	float timeLimit;
	bool oneTimeOnly;
	Sprite sp;

};

#endif