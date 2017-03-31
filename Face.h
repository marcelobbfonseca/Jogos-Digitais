#include "GameObject.h"

#ifndef FACE_H
#define FACE_H

#define FULL_HEALTH 30
class Face : public GameObject
{
public:
	Face(float x, float y);
	void Damage(int damage);

	~Face();
private:
	int hitpoints;
	Sprite sp;
};

#endif