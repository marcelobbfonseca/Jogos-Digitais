#pragma once

#include <iostream>
#include <memory>
using namespace std;

class inputManager
{
public:
	inputManager();
	
	void Update();

	bool Keypress(int key);
	bool KeyRelease(int key);
	bool IsKeyDown(int key);
	
	bool MousePress(int button);
	bool MouseRelease(int button);
	bool isMouseDown(int button);
	
	int GetMouseX();
	int GetMouseY();

	bool QuitRequested();

	static inputManager& GetInstance();

	~inputManager();
private:
	bool mouseState[6];
	int mouseUpdate[6];
	
	bool quitRequested;
	int updateCounter;
	int mouseX, mouseY;
	std::unordered_map<int, bool> KeyState;
	std::unordered_map<int, int> KeyUpdate;
};