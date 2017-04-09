#include "TileSet.h"

#define TILES_NUMBER 1



TileSet::TileSet(int tileWidth, int tileHeight, string file): tileSet(file){
	//seta as dimensoes e abre o sprite
	this->tileWidth = tileWidth;
	this->tileHeight = tileHeight;
	

	//BUILD rows and columns

}

void TileSet::Render(unsigned index, float x, float y){
	if(index > TILES_NUMBER-1)
		exit(1);

	//calcule tamanho e sete clip desejado. renderize na pos dada
	//tileSet.SetClip(x,y,64,64);
}

int TileSet::GetTileWidth(){
	return tileWidth;
}
int TileSet::GetTileHeight(){
	return tileHeight;
}

TileSet::~TileSet(){

}