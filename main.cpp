#ifdef _WIN32
	//windows
#elif __APPLE__
	#include "TargetConditionals.h"
#elif __linux__
	//linux
#else
	//something else 0_0
#endif

#include <iostream>
#include <string>

using namespace std;

#include "Game.h"
#include "State.h"
#include "Sprite.h"


//use valgrind --leak-check=full ./vamola

int main(int argc, char const *argv[]){
	int height, width;
	string title = "Marcelo 110130766";

	width = 1024;
	height = 600;
	
	Game game(title,width,height);
	
	game.Run();

	return 0;
}

