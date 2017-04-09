
#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Resources
{
public:
	Resources();
	static SDL_Texture* GetImage(string file);
	static void ClearImages();
	~Resources();
private:
	static unordered_map<string, SDL_Texture*> imageTable;
};