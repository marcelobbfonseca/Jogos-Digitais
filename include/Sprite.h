#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#ifndef SPRITE_H
#define SPRITE_H
#include <iostream>
#include <string>
using std::string;


class Sprite
{
public:
	Sprite();
	Sprite(string file,int frameCount=1, float frameTime=1.0 ); //
	void Open(string file);
	void SetClip(int x, int y, int w, int h);
	void Render( int x, int y, float angle=0);
	int GetWidth();
	int GetHeight();
	bool IsOpen();
	SDL_Texture* GetTexture();

	void SetScaleX(float x);
	void SetScaleY(float y);

	void Update(float dt);
	void SetFrame(int frame);
	void SetFrameCount(int frameCount);
	void SetFrameTime(float frameTime);

	int GetFrameCount();
	float GetFrameTime();

	~Sprite();
private:
	SDL_Texture* texture;
	SDL_Rect clipRect; //clipping rectangle
	int width, height;
	float scaleX, scaleY;
	
	int frameCount, currentFrame;
	float frameTime, timeElapsed;

	
};


#endif