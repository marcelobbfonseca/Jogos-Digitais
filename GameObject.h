
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
public:
	GameObject();
	void Update(float dt);
	void Render();
	bool isDead();
	~GameObject();
	Rect box //dimensao
	
};


#endif