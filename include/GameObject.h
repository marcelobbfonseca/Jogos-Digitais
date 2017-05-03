#pragma once

#include "SDL2/SDL.h"
#include "Rect.h"

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

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