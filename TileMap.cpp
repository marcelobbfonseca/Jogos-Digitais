#include <iostream>
#include <string>
#include <fstream> //used to read tileMap file

using namespace std;
#include "TileSet.h"
#include "TileMap.h"


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


void TileMap::SetTileSet(TileSet* tileSet){
	//troca o tileset em uso
}
//retorna uma referencia ao x,y,z de tileMatrix
/*int& TileMap::At(int x, int y, int z = 0){
	
	return &x;
}*/

void TileMap::RenderLayer(int layer, int cameraX /*= 0*/, int cameraY /*= 0*/){
	
	//renderiza uma camada do mapa. tile a tile
		//abrir file e ler ate acabar. read -1 save
		//compensar deslocamento da camera
		//considerar o tamanho de cada tile. usar get width e height de tile
}

void TileMap::Render(int cameraX /*=0*/, int cameraY /*=0*/){
	//reneriza todas as camadas do mapa
	RenderLayer(0,cameraX,cameraY); //plain
	RenderLayer(1,cameraX,cameraY); //sky
}

TileMap::~TileMap(){

}