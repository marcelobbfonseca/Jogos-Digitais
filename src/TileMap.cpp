#include <iostream>
#include <string>
#include <fstream> //used to read tileMap file

using std::cout;
using std::string;
#include "TileMap.h"
#include "error.h"

#define PLAIN 0
#define SKY 1


TileMap::TileMap(string file, TileSet* tileSet): tileSet(tileSet){
	Load(file);
	//SetTileSet(tileSet);

}

void TileMap::Load(string file){ 
	int tilesTotal, tileId;
	FILE *fp;

	fp = fopen(file.c_str(), "r");

	if(fp== NULL)
		ErrorExit(__LINE__, "Read File fp is null. File cold not be found.",__FILE__);

	if(fscanf(fp, "%d,%d,%d,", &mapWidth, &mapHeight, &mapDepth))
		tilesTotal = mapWidth*mapHeight*mapDepth; //calculate total tiles on tilemap

	for(int i=0; i < tilesTotal; i++){ //fill in vector tile matrix 
		if(fscanf(fp, " %d,", &tileId)){
			tileMatrix.push_back(tileId-1);
		}else{
			ErrorExit( __LINE__,"Error on tileMap read. Reached EOF. tiles missing!",__FILE__);
		}
	}

	return;

}


void TileMap::SetTileSet(TileSet *tileSet){
	this->tileSet = tileSet;
}

//formula:[x + (y * W) ) + ( z * W * H )]
int& TileMap::At(int x, int y, int z /*= 0*/){
	int matrixIndex;
	matrixIndex = (x + (y * mapWidth) + (z * mapWidth * mapHeight) );
	return (tileMatrix.at(matrixIndex)); //return reference to pos:x,y,z of tileMatrix
}

void TileMap::RenderLayer(int layer, int cameraX /*= 0*/, int cameraY /*= 0*/){
	float tileX, tileY;

	//render a layer from the map. tile by tile
	for(int x = 0; x < mapWidth; x++){
		for(int y = 0; y < mapHeight; y++){
				
				tileX = (float)( (x) * tileSet->GetTileWidth() );
				tileY = (float)( (y) * tileSet->GetTileHeight() );
				
				tileSet->Render(At(x, y, layer), (tileX-cameraX), tileY-cameraY); //(index,x,y)
		}
	}


	//futuramente: compensar deslocamento da camera
	return;
}

void TileMap::Render(int cameraX /*=0*/, int cameraY /*=0*/){
	//reneriza todas as camadas do mapa
	RenderLayer(PLAIN,cameraX,cameraY); //plain 0
	RenderLayer(SKY,cameraX,cameraY); //sky 1

}

TileMap::~TileMap(){

}