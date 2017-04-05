class TileMap
{
public:
	TileMap(string file, TileSet* tileSet);
	void Load(string file);
	int& At(int x, int y, int z = 0);
	void Render(int cameraX = 0, int cameraY = 0);
	void RenderLayer(int layer, int cameraX = 0, int cameraY = 0);
	int Getwidth();
	int GetHeight();
	int GetDepth();
	~TileMap();
private:
	std::vector<int> leMatrix 
­ 	TileSet* tileSet;
­ 	int mapWidth;
­ 	int mapHeight; 
­ 	int mapDepth;	
};