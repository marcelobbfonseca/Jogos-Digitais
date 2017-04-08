
#pragma once


#include <iostream>
#include <string>
using namespace std;
#include "Sprite.h"

class TileSet
{
public:
	TileSet(int tileWidth, int tileHeight, string file);
	void Render(unsigned index, float x, float y);
	int GetTileWidth();
	int GetTileHeight();
	~TileSet();
private:
	Sprite tileSet;
	int rows, columns, tileHeight, tileWidth;
	
};
