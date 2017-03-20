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
	//check if theres an IMG loaded first
	int dimensao;
	if(1)			//game->GetRenderer()
	if(IMG_LoadTexture(0, 0/*path*/) ==nullptr){//can return nullptr.treat
		cout << SDL_GetError() << endl;
		exit(1);
	}
	dimensao = SDL_QueryTexture(texture ,nullptr,nullptr, &width,&height);//passar end de w e h
	
	SetClip(0,0,width,height);
	Render(0,0);
}


void Sprite::SetClip(int x, int y, int w, int h){
	width = w;
	height = h;
	//clipRect = 
}

void Sprite::Render(int x, int y){

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

