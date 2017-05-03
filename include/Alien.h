#pragma once
#include <vector>
#include <queue>

#include "Sprite.h"
#include "GameObject.h"

#include "Vec2.h"
#include "Minion.h"


#define ALIEN_MOVE_SPEED 8
#define ALIEN_ROTATION_SPEED 0.01
class Alien : public GameObject
{
public:
	Alien(float x, float y, int nMinions);
	~Alien();

	//herda de gameobject
	void Update(float dt);
	void Render();
	bool isDead();
private:
	class Action;
	Sprite sp;
	Vec2 speed;	
	int hp;
	std::queue<Action> taskQueue;
	std::vector<Minion> minionArray;
	class Action
	{
	public:
		enum ActionType{MOVE, SHOOT} type;
		Action(ActionType type, float x, float y);
		Vec2 pos;
	};
};

















