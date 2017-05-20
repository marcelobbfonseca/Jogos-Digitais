
#ifndef STAGESTATE_H
#define STAGESTATE_H

#include <vector>
#include <memory>
#include "Sprite.h"
#include "GameObject.h"
#include "TileSet.h"
#include "TileMap.h"
#include "InputManager.h"
#include "State.h"
#include "Music.h"

class StageState : public State
{
public:
	StageState();
	~StageState();

	//bool QuitRequested();
	//void LoadAssets();
	void Update(float dt);
	void Render();
	//void AddObject(GameObject* ptr);
	void Pause();
	void Resume();

private:
	Sprite bg;
	
	TileSet tileSet;
	TileMap *tileMap;

	//bool quitRequested;
	//std::vector<std::unique_ptr<GameObject>> objectArray;
	InputManager &inputManager;
	Music music;



};

#endif