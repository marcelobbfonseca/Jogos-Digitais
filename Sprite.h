#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#ifndef MEUPROJETO_SPRITE_H
#define MEUPROJETO_SPRITE_H


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
	~Sprite();
private:
	SDL_Texture* texture;
	SDL_Rect clipRect; //clipping rectangle
	int width, height;

	
};


#endif