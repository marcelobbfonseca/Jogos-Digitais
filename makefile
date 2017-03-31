run: 
	g++ -std=c++11 -o vamola main.cpp Game.cpp Sprite.cpp State.cpp -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -O2 -g
