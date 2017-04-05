#define TILES_NUMBER 1

TileSet::TileSet(int tileWidth, int tileHeight, string file){

}

TileSet::Render(unsigned index, float x, float y){
	if(index > TILES_NUMBER-1)
		exit(1);

	//calcule e sete clip desejado

}

TileSet::GetTileWidth(){
	return tileWidth;
}
TileSet::GetTileHeight(){
	return tileHeight;
}

TileSet::~TileSet(){

}