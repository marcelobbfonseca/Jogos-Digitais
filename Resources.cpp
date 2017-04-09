#include "Resources.h"
#include "Game.h"
//#include "error.h"


#include <iostream>
#include <string>
using namespace std;


unordered_map<string, SDL_Texture*> Resources::imageTable;


SDL_Texture* Resources::GetImage(string file){
	const char *const_file = file.c_str();
	Game& game = Game::GetInstance();

	SDL_Texture* texture;
	unordered_map< string, SDL_Texture* >::const_iterator got = imageTable.find(file);
	
	
	//checa se a img existe. Se sim: retorne o ponteiro  |Se nao:Carrega e insere o par (path,ptr) na tabela
  	if ( got == imageTable.end() ){
    	//not found
    	texture = IMG_LoadTexture( game.GetRenderer(), const_file);
  		if (texture == nullptr)
			//cout << SDL_GetError() << endl;
		imageTable.emplace(file, texture);
	}
  	else{
    	//Exist! got->first and got->second
    	texture = got->second;
  	}

	return texture;
}

//chamada ao fim de game loop
void Resources::ClearImages(){
	std::unordered_map<string, SDL_Texture*>::iterator i;
	
	for(i = imageTable.begin(); i != imageTable.end(); i++){
			SDL_DestroyTexture((*i).second);
	}
	imageTable.clear();
	
}