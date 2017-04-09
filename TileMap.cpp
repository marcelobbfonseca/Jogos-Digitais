#include <iostream>
#include <string>
#include <fstream> //used to read tileMap file

using namespace std;
#include "TileMap.h"

#define PLAIN 0
#define SKY 1


TileMap::TileMap(string file, TileSet* tileSet){
	Load(file);
	//SetTileSet(tileSet);

}

void TileMap::Load(string file){ 
	int tilesTotal, tileId;
	FILE *fp;

	fp = fopen(file.c_str(), "r");

	if(fp== NULL){
		cerr << "Read File fp is null. File cold not be found.";
		exit(1); 
	}

	if(fscanf(fp, "%d,%d,%d,", &mapWidth, &mapHeight, &mapDepth))
		tilesTotal = mapWidth*mapHeight*mapDepth; //calculate total tiles on tilemap

	for(int i=0; i < tilesTotal; i++){ //fill in vector tile matrix 
		if(fscanf(fp, " %d,", &tileId)){
			tileMatrix.push_back(tileId-1);
		}else{
			cerr << "Error on tileMap read. Reached EOF. tiles missing!";
			exit(1); 
		}
	}

	return;

}


void TileMap::SetTileSet(TileSet *tileSet){
	this->tileSet = tileSet;
}
//return reference to pos:x,y,z of tileMatrix
int& TileMap::At(int x, int y, int z /*= 0*/){
	int matrixIndex;
	//formula:[x + (y * W) ) + ( z * W * H )]
	matrixIndex = (x + (y * mapWidth) + (z * mapWidth * mapHeight) );
	return ((int&)tileMatrix.at(matrixIndex));
}

void TileMap::RenderLayer(int layer, int cameraX /*= 0*/, int cameraY /*= 0*/){
	int index;
	float tile_x, tile_y;

	//render a layer from the map. tile by tile
	for(int x = 0; x < mapWidth; x++){
		for(int y = 0; y < mapHeight; y++){
			index= At(x, y, layer);
			if(0 <= index){
				tile_x = (float)x*tileSet->GetTileWidth();
				tile_y = (float)y*tileSet->GetTileHeight();
				tileSet->Render(At(x, y, layer), tile_x, tile_y); //(index,x,y)
			}
		}
	}



	//compensar deslocamento da camera
	//considerar o tamanho de cada tile. usar get width e height de tile
	return;
}

void TileMap::Render(int cameraX /*=0*/, int cameraY /*=0*/){
	//reneriza todas as camadas do mapa
	RenderLayer(PLAIN,cameraX,cameraY); //plain
	RenderLayer(SKY,cameraX,cameraY); //sky
}

TileMap::~TileMap(){

}