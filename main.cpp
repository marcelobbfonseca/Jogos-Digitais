// g++ -std=c++11 teste.cpp -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
#include <iostream>
#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"

using namespace std;
#include "Game.h"
#include "State.h"
#include "Sprite.h"



int main(int argc, char const *argv[]){
	int height, width;
	string title = "Marcelo 110130766";

	width = 1024;
	height = 600;
	
	Game game(title,width,height);
	
	//game.run();

	return 0;
}

