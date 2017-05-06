#include "TileSet.h"
#include "Game.h"
#include "error.h"

#define TILES_NUMBER 1



TileSet::TileSet(int tileWidth, int tileHeight, string file): tileSet(file){
	//seta as dimensoes e abre o sprite
	this->tileWidth = tileWidth;
	this->tileHeight = tileHeight;
	

	//BUILD rows and columns
	columns = tileSet.GetWidth()/tileWidth;
	rows = tileSet.GetHeight()/tileHeight;
}

void TileSet::Render(int index, float x, float y){
	int newX, newY, tileNum;
	tileNum = (rows * columns) - 1;


	if((index > tileNum) or (index<0)){
		return;
	}else{
		//calcule tamanho e sete clip desejado. renderize na pos dada
		newX = index % columns;
		newY = index / columns;

		tileSet.SetClip(newX * tileWidth, newY * tileHeight, tileWidth, tileHeight);
		tileSet.Render(x,y,0);


	}
}

int TileSet::GetTileWidth(){
	return tileWidth;
}
int TileSet::GetTileHeight(){
	return tileHeight;
}

TileSet::~TileSet(){

}