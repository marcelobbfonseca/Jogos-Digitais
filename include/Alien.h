#ifndef ALIEN_H
#define ALIEN_H

#include <vector>
#include <queue>

#include "Sprite.h"
#include "GameObject.h"

#include "Vec2.h"
#include "Minion.h"

#include "Timer.h"

#define ALIEN_MOVE_SPEED 280
#define ALIEN_ROTATION_SPEED 0.01
class Alien : public GameObject
{
public:
	Alien(float x, float y, int nMinions);
	~Alien();

	void Update(float dt);
	void Render();
	bool isDead();

	bool Is(string type);
	void NotifyCollision(GameObject& other);
	static int alienCount;


private:
	Sprite sp;
	Vec2 speed;	
	int hp;
	std::vector<Minion> minionArray;
	
	enum AlienState{MOVING, RESTING} state;
	Timer restTimer;
	Vec2 destination;

};

#endif













