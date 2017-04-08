#include <iostream>
#include <string>
using namespace std;
#include "TileSet.h"
#include "TileMap.h"


TileMap::TileMap(string file, TileSet* tileSet){
	Load(file);
	SetTileSet(tileSet);

}

void TileMap::Load(string file){
	//map/tileMap.txt
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