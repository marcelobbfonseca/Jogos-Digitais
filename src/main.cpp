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

using std::cout;
using std::string;

#include "Game.h"
#include "StageState.h"
#include "Sprite.h"
#include "error.h"
#include "TitleState.h"

//use valgrind --leak-check=full ./vamola

int main(int argc, char const *argv[]){
	int height, width;
	string title = "Marcelo 110130766";

	width = 1024;
	height = 600;
	
	Game game(title,width,height);
	game.Push( new TitleState());
	//game.Push( new StageState());
	
	game.Run();

	return 0;
}



//functions
void Warning(int line, string description, string file){ //(line, error description, file)
	cout << "\nLine:"<< line << " " << description << " File: " << file << endl;
	return;
}

void ErrorExit(int line, string description, string file){ //(line, error description, file)
	cerr << "\nLine:"<< line << " " << description << " File: " << file << endl;
	exit(1);
}

void debugInt(string description, int value, string file, int line ){
	cout << description << " " << value << " LINE: " << line << " FILE: "<< file << endl;
}
void debugFloat(string description, float value, string file, int line  ){
	cout << description << " " << value << " LINE: " << line << " FILE: " << file<< endl;
}
void debugString(string description, string value, string file, int line  ){
	cout << description << " " << value << " LINE: " << line << " FILE: " << file << endl;
}