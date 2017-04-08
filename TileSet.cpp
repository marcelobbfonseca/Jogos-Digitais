#include "TileSet.h"

#define TILES_NUMBER 1



TileSet::TileSet(int tileWidth, int tileHeight, string file){
	//seta as dimensoes e abre o sprite
	this->tileWidth = tileWidth;
	this->tileHeight = tileHeight;
	//tileSet(file);

}

void TileSet::Render(unsigned index, float x, float y){
	if(index > TILES_NUMBER-1)
		exit(1);

	//calcule e sete clip desejado

}

int TileSet::GetTileWidth(){
	return tileWidth;
}
int TileSet::GetTileHeight(){
	return tileHeight;
}

TileSet::~TileSet(){

}