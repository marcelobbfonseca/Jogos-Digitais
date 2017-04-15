#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#ifndef SPRITE_H
#define SPRITE_H
#include <iostream>
#include <string>
using namespace std;


class Sprite
{
public:
	Sprite();
	Sprite(string file);
	void Open(string file);
	void SetClip(int x, int y, int w, int h);
	void Render( int x, int y);
	int GetWidth();
	int GetHeight();
	bool IsOpen();
	SDL_Texture* GetTexture();
	~Sprite();
private:
	SDL_Texture* texture;
	SDL_Rect clipRect; //clipping rectangle
	int width, height;

	
};


#endif