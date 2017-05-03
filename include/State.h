

#ifndef STATE_H
#define STATE_H

#include <vector>
#include <memory>
#include "Sprite.h"
#include "GameObject.h"
#include "TileSet.h"
#include "TileMap.h"
#include "InputManager.h"
class State
{
public:
	State();
	~State();

	bool QuitRequested();
	void LoadAssets();
	void Update();
	void Render();
	// metodos trab2
	//void Input();
	//void AddObject(int mouseX, int mouseY);
	void AddObject(GameObject* ptr);
private:
	Sprite bg;
	
	TileSet tileSet;
	TileMap *tileMap;

	bool quitRequested;
	std::vector<std::unique_ptr<GameObject>> objectArray;
	InputManager &inputManager;



};

#endif