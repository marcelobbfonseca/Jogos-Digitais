#include "Sprite.h"

Sprite::Sprite(){
	texture = nullptr;

}
Sprite::Sprite(string file){
	texture = nullptr;
	Open(file);
	
}
void Sprite::Open(string file){
	//check if theres an IMG loaded first
	if(1)
	IMG_LoadTexture(Game->GetRenderer(), path);//can return nullptr.treat

}

Sprite::~Sprite(){
	SDL_DestroyTexture(SDL_Texture*);
}

