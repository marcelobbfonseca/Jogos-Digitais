
#ifndef RESOURCES_H
#define RESOURCES_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"

#include <iostream>
#include <string>
#include <unordered_map>
using std::unordered_map;
using std::string;
class Resources
{
public:
	Resources();
	~Resources();

	static SDL_Texture* GetImage(string file);
	static void ClearImages();

	static Mix_Music* GetMusic(string file);
	static void ClearMusic();

	static Mix_Chunk* GetSound(string file);
	static void ClearSound();

	static TTF_Font* GetFont();
	static void ClearFont();

private:
	static unordered_map<string, SDL_Texture*> imageTable;
	static unordered_map<string, Mix_Music*> musicTable;
	static unordered_map<string, Mix_Chunk*> soundTable;
	static unordered_map<string, TTF_Font*> fontTable;
}; 

#endif