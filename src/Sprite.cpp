#include <iostream>
#include <string>
using std::cout;
using std::endl;

#include "Sprite.h"
#include "Game.h"
#include "Resources.h"
#include "error.h"

#ifndef PI
	#define PI 3.141592
#endif

Sprite::Sprite(){
	texture = nullptr;
	scaleX=1;
	scaleY=1;
	this->frameCount = 1;
	this->frameTime = 1.0;
	this->timeElapsed = 0.0;
	this->currentFrame = 1;

}
Sprite::Sprite(string file, int frameCount /*=1*/, float frameTime /*=1.0*/){
	texture = nullptr;
	scaleX=1;
	scaleY=1;
	this->frameCount = frameCount;
	this->frameTime = frameTime;
	this->timeElapsed = 0.0;
	this->currentFrame = 1;
	Open(file);
	
}
void Sprite::Open(string file){
	int dimensao;
	const char *const_file = file.c_str();
	Game& game = Game::GetInstance();
	

	texture = Resources::GetImage(file);
	if (texture == nullptr){
		ErrorExit(__LINE__, SDL_GetError(), __FILE__);
	}
	if(SDL_QueryTexture(texture ,nullptr,nullptr, &width,&height)){ //pass address of 'w' and 'h'
		ErrorExit(__LINE__, SDL_GetError(), __FILE__);
	}
	SetClip(0,0,width/frameCount,height);
}

void Sprite::SetClip(int x, int y, int w, int h){
	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;
}
//wrapper for RenderCopy
void Sprite::Render(int x, int y, float angle){
	
	float degree = (angle * 180.0)/PI; //convert from radian to degree
	
	Game& game = Game::GetInstance();
	SDL_Rect destRetangle;
	
	destRetangle.x = x;
	destRetangle.y = y;
	destRetangle.w = clipRect.w*scaleX;
	destRetangle.h = clipRect.h*scaleY;
	
	if(SDL_RenderCopyEx(game.GetRenderer(), texture, &clipRect, &destRetangle,degree,NULL,SDL_FLIP_NONE)!=0)
		ErrorExit(__LINE__, SDL_GetError(), __FILE__);
}

int Sprite::GetHeight(){
	return height * scaleY;
}

int Sprite::GetWidth(){
	return ((width/frameCount) * scaleX);
}

bool Sprite::IsOpen(){
	if(texture)
		return true;
	else
		return false;
}

void Sprite::Update(float dt){
	timeElapsed += dt;
	if(timeElapsed>frameTime){
		timeElapsed-=frameTime;
		currentFrame++;
		//chegou no ultimo frame, volta pro primeiro
		if(currentFrame>frameCount)
			currentFrame=1;
		//printf("timeElapsed:%f frameTime: %f \t currentFrame: %d frameCount:%d\n", timeElapsed,frameTime ,currentFrame,frameCount);
		SetFrame(currentFrame);//setclip to next frame
		
	} 

}

void Sprite::SetScaleX(float x){
	scaleX = x;
}

void Sprite::SetScaleY(float y){
	scaleY = y;
}


void Sprite::SetFrame(int frame){
	this->currentFrame = frame;
	int x = (currentFrame-1) * (width/frameCount);//currentFrame starts with 0 to work
	this->clipRect.x= x;

}

void Sprite::SetFrameCount(int frameCount){
	this->frameCount = frameCount;
	clipRect.w= width/frameCount;
}

void Sprite::SetFrameTime(float frameTime){
	this->frameTime = frameTime;
}


int Sprite::GetFrameCount(){
	return frameCount;
}
float Sprite::GetFrameTime(){
	return frameTime;
}


Sprite::~Sprite(){
	//resources far´a isso
	//SDL_DestroyTexture(texture);
}

SDL_Texture* Sprite::GetTexture(){
	return texture;
}