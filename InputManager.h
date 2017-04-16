#pragma once

#include <iostream>
#include <unordered_map>
using namespace std;

class InputManager
{
public:
	InputManager();
	
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

	static InputManager& GetInstance(); //singleton

	~InputManager();
private:
	bool mouseState[6];
	int mouseUpdate[6];
	
	bool quitRequested;
	int updateCounter;
	int mouseX, mouseY;
	std::unordered_map<int, bool> KeyState;
	std::unordered_map<int, int> KeyUpdate;
};