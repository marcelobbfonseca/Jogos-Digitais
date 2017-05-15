#ifndef ALIEN_H
#define ALIEN_H

#include <vector>
#include <queue>

#include "Sprite.h"
#include "GameObject.h"

#include "Vec2.h"
#include "Minion.h"

#include "Timer.h"

#define ALIEN_MOVE_SPEED 155
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
	class Action;
	Sprite sp;
	Vec2 speed;	
	int hp;
	std::queue<Action> taskQueue;
	std::vector<Minion> minionArray;
	//
	class Action
	{
	public:
		enum ActionType{MOVE, SHOOT} type;
		Action(ActionType type, float x, float y);
		Vec2 pos;
	};
	//
	enum AlienState{MOVING, RESTING};
	AlienState state;
	Timer restTimer;
	Vec2 destination;

};

#endif













