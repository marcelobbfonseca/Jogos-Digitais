#include "Resources.h"
#include "Game.h"
#include "error.h"


#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::unordered_map;
using std::endl;
unordered_map<string, SDL_Texture*> Resources::imageTable;

SDL_Texture* Resources::GetImage(string file){
	//header: local variables declarations	
	const char *const_file = file.c_str();
	Game& game = Game::GetInstance();
	SDL_Texture* texture;
	unordered_map< string, SDL_Texture* >::const_iterator got = imageTable.find(file);
	
	//chehck if img exist. yes?: return pointer  | no?: load and insert pair (path,ptr) on table
  	if ( got == imageTable.end() ){
    	//not found
    	texture = IMG_LoadTexture( game.GetRenderer(), const_file);
  		if (texture == nullptr){
			cout << SDL_GetError() << __LINE__ << __FILE__ << endl;
			exit(1);
  		}

		imageTable.emplace(file, texture);
	}
  	else{
    	//Got it! got->first and got->second
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