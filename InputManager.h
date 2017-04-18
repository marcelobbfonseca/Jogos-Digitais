#pragma once

#include <iostream>
#include <unordered_map>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"


#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT
#define UP_ARROW_KEY SDLK_UP
#define DOWN_ARROW_KEY SDLK_DOWN
#define ESCAPE_KEY SDLK_ESCAPE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT

#define LEFT_ALT_KEY SDLK_LALT
#define LEFT_CTRL_KEY SDLK_LCTRL
#define LEFT_SHIFT_KEY SDLK_LSHIFT
#define ESPACE_KEY SDLK_SPACE
#define RIGHT_MOUSE_BUTTON SDL_BUTTON_RIGHT
#define MIDDLE_MOUSE_BUTTON SDL_BUTTON_MIDDLE

class InputManager
{
public:
	InputManager();
	
	void Update();

	bool KeyPress(int key);
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
	std::unordered_map<int, bool> keyState;
	std::unordered_map<int, int> keyUpdate;
	//bool keyState[416];
	//int keyUpdate[416];
};
