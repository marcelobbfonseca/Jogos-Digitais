// g++ -std=c++11 teste.cpp -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
#include <iostream>
#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"

using namespace std;
#include "Game.h"



void validatePointer(){
	
}

int main(int argc, char const *argv[]){
	int heigth, width;
	string title;

	title = "Cerviço Cecreto Sentral";
	heigth = 400;
	width = 600;

	Game game(title,width,heigth);
	

	return 0;
}

