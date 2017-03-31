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
	Game& game = Game::GetInstance();
	
	
	//check if theres an IMG loaded first on texture
	if(IsOpen())
		SDL_DestroyTexture(texture);

	texture = IMG_LoadTexture( game.GetRenderer(), const_file); //can return nullptr.treat
	if (texture == nullptr){
		cout << SDL_GetError() << endl;
		exit(1);
	}
	if(SDL_QueryTexture(texture ,nullptr,nullptr, &width,&height)){ //pass address of 'w' and 'h'
		cout <<__LINE__<< SDL_GetError() <<  __FILE__<< endl;
		exit(1);
	}
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
	

	Game& game = Game::GetInstance();
	SDL_Rect destRetangle;
	
	destRetangle.x = x;
	destRetangle.y = y;
	destRetangle.w = clipRect.w;
	destRetangle.h = clipRect.h;
	

	if(SDL_RenderCopy(game.GetRenderer(), texture, &clipRect, &destRetangle)!=0){
		
		cout <<__LINE__<<" Error:SDL_RenderCopy retornou null "<< __FILE__<< SDL_GetError() << endl;
		exit(1);
	}


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

