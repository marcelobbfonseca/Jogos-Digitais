#include "TileSet.h"
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

void TileSet::Render(unsigned index, float x, float y){
	int newX, newY, tileNum;
	tileNum = (rows * columns) - 1;
	Warning(__LINE__, "aloo" ,__FILE__);

	if(index > tileNum)
		ErrorExit(__LINE__, "Index nao pode ser maior que o numero de tiles-1 " ,__FILE__);

	//calcule tamanho e sete clip desejado. renderize na pos dada
	//tileSet.SetClip(x,y,64,64);
	newX = index % columns;
	newY = index / columns;

	tileSet.SetClip(newX,newY,tileWidth,tileHeight);
	tileSet.Render(x,y);
	Warning(__LINE__, "aloo" ,__FILE__);

}

int TileSet::GetTileWidth(){
	return tileWidth;
}
int TileSet::GetTileHeight(){
	return tileHeight;
}

TileSet::~TileSet(){

}