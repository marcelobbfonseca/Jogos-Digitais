
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "SDL2/SDL.h"
#include "Rect.h"
#include <string>

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void Update(float dt)=0;
	virtual void Render()=0;
	virtual bool isDead()=0;

	virtual void NotifyCollision(GameObject& other)=0;
	virtual bool Is(std::string type)=0;

	Rect box; //dimension
	float rotation; //in radians
	
};


#endif