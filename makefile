run: 
	g++ -std=c++11 -o vamola main.cpp Game.cpp Sprite.cpp State.cpp Face.cpp GameObject.cpp TileSet.cpp TileMap.cpp -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -O2 -g
