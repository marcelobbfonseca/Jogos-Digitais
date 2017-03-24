#include <iostream>
#include <string>
using namespace std;
#include "Sprite.h"
#include "Game.h"
Sprite::Sprite(){
	texture = nullptr;

}
Sprite::Sprite(string file){
	texture = nullptr;
	Open(file);
	
}
void Sprite::Open(string file){
	int dimensao;
	const char *const_file = file.c_str();
	
	//check if theres an IMG loaded first on texture
	if(IsOpen())
		SDL_DestroyTexture(texture);
	//render = game->GetRenderer();
	// 					render
	if(IMG_LoadTexture( 0, const_file) ==nullptr){//can return nullptr.treat
		cout << SDL_GetError() << endl;
		exit(1);
	}
	dimensao = SDL_QueryTexture(texture ,nullptr,nullptr, &width,&height);//passar end de w e h
	
	SetClip(0,0,width,height);
	Render(0,0);
}


void Sprite::SetClip(int x, int y, int w, int h){
	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;
}

//wrapper for RenderCopy
void Sprite::Render(int x, int y){
	SDL_Rect destRetangle;
	destRetangle.x = x;
	destRetangle.y = y;
	destRetangle.w = clipRect.w;
	destRetangle.h = clipRect.h;
	//arguments must be const for SDL_RenderCopy
	const SDL_Rect* const_destRetangle = &destRetangle; 
	const SDL_Rect* const_clipRect = &clipRect;

	//game->GetRenderer()
	SDL_RenderCopy(/*SDL_Renderer* renderer*/ 0, texture, const_clipRect, const_destRetangle);


}

int Sprite::GetHeight(){
	return height;
}

int Sprite::GetWidth(){
	return width;
}

bool Sprite::IsOpen(){
	if(texture)
		return true;
	else
		return false;
}

Sprite::~Sprite(){
	SDL_DestroyTexture(texture);
}

