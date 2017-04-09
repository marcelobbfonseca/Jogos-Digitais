
#pragma once //substitui o ifndef. mesma coisa!

#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <memory>

#include "TileSet.h"

class TileMap
{
public:
	TileMap(string file, TileSet* tileSet);
	void Load(string file);
	void SetTileSet(TileSet* tileSet);
	//int& At(int x, int y, int z = 0);
	void Render(int cameraX = 0, int cameraY = 0);
	void RenderLayer(int layer, int cameraX = 0, int cameraY = 0);
	int Getwidth();
	int GetHeight();
	int GetDepth();
	~TileMap();
private:
	std::vector<int> tileMatrix;
	Sprite tileSet;
	int mapWidth, mapHeight, mapDepth;
};
