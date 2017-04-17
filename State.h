#include "Sprite.h"
#include "GameObject.h"
#include "TileSet.h"
#include "TileMap.h"
#include "InputManager.h"

#ifndef MEUPROJETO_STATE_H
#define MEUPROJETO_STATE_H

#include <vector>
#include <memory>

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
	void Input();
	void AddObject(int mouseX, int mouseY);
	
private:
	Sprite bg;
	
	TileSet tileSet;
	TileMap *tileMap;

	bool quitRequested;
	//atributos trab2
	std::vector<std::unique_ptr<GameObject>> objectArray;
	InputManager &inputManager;

};

#endif