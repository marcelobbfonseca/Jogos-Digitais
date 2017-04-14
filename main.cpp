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
#include "error.h"


//use valgrind --leak-check=full ./vamola

int main(int argc, char const *argv[]){
	int height, width;
	string title = "Marcelo 110130766";

	width = 1024;
	height = 600;
	
	Game game(title,width,height);
	Warning(__LINE__, "alo" ,__FILE__);	
	game.Run();

	return 0;
}

void Warning(int line, string description, string file){ //(line, error description, file)
	cout << "\nLine:"<< line << " " << description << " File: " << file << endl;
	return;
}

void ErrorExit(int line, string description, string file){ //(line, error description, file)
	cerr << "\nLine:"<< line << " " << description << " File: " << file << endl;
	exit(1);
}