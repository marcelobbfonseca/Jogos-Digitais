#include <iostream>
#include <string>
using std::cout;
using std::string;
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

}
Sprite::Sprite(string file){
	texture = nullptr;
	scaleX=1;
	scaleY=1;
	Open(file);
	
	
}
void Sprite::Open(string file){
	int dimensao;
	const char *const_file = file.c_str();
	Game& game = Game::GetInstance();
	

	texture = Resources::GetImage(file);
	//texture = IMG_LoadTexture( game.GetRenderer(), const_file); //can return nullptr.treat
	if (texture == nullptr){
		ErrorExit(__LINE__, SDL_GetError(), __FILE__);
	}
	if(SDL_QueryTexture(texture ,nullptr,nullptr, &width,&height)){ //pass address of 'w' and 'h'
		ErrorExit(__LINE__, SDL_GetError(), __FILE__);
	}
	SetClip(0,0,width,height);

	Render(0,0,0);
}


void Sprite::SetClip(int x, int y, int w, int h){
	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;
}

//wrapper for RenderCopy
void Sprite::Render(int x, int y, float angle){
	float degree = (angle * 180)/PI; //convert from radian to degree
	
	Game& game = Game::GetInstance();
	SDL_Rect destRetangle;
	
	destRetangle.x = x;
	destRetangle.y = y;
	destRetangle.w = clipRect.w*scaleX;
	destRetangle.h = clipRect.h*scaleY;
	

	if(SDL_RenderCopyEx(game.GetRenderer(), texture, &clipRect, &destRetangle,degree,NULL,SDL_FLIP_NONE)!=0){
		ErrorExit(__LINE__, SDL_GetError(), __FILE__);
	}


}

int Sprite::GetHeight(){
	return height * scaleY;
}

int Sprite::GetWidth(){
	return width * scaleX;
}

bool Sprite::IsOpen(){
	if(texture)
		return true;
	else
		return false;
}

void Sprite::SetScaleX(float x){
	scaleX = x;
}

void Sprite::SetScaleY(float y){
	scaleY = y;
}

Sprite::~Sprite(){
	//resources far´a isso
	//SDL_DestroyTexture(texture);
}

SDL_Texture* Sprite::GetTexture(){
	return texture;
}