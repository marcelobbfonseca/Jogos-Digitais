
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "SDL2/SDL.h"
#include "Rect.h"

class GameObject
{
public:
	GameObject();
	virtual void Update(float dt)=0;
	virtual void Render()=0;
	virtual bool isDead()=0;
	~GameObject();
	Rect box; //dimension
	float rotation; //in radians
	
};


#endif