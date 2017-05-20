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
unordered_map<string, Mix_Music*> Resources::musicTable;
unordered_map<string, Mix_Chunk*> Resources::soundTable;
unordered_map<string, TTF_Font*> Resources::fontTable;


SDL_Texture* Resources::GetImage(string file){
	//header: local variables declarations	
	const char *const_file = file.c_str();
	Game& game = Game::GetInstance();
	SDL_Texture* texture;
	unordered_map< string, SDL_Texture* >::const_iterator got = imageTable.find(file);
	
	//check if img exist. yes?: return pointer  | no?: load and insert pair (path,ptr) on table
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

Mix_Music* Resources::GetMusic(string file){
	const char *const_file = file.c_str();
	Game& game = Game::GetInstance();
	Mix_Music* music;
	unordered_map< string, Mix_Music* >::const_iterator got = musicTable.find(file);
	
	//check if music exist. yes?: return pointer  | no?: load and insert pair (path,ptr) on table
  	if ( got == musicTable.end() ){
    	//not found
    	music = Mix_LoadMUS(const_file);
  		if (music == nullptr)
			ErrorExit(__LINE__, Mix_GetError() ,__FILE__);
  		

		musicTable.emplace(file, music);
	}
  	else{
    	//Got it! got->first and got->second
    	music = got->second;
  	}

	return music;
}

void Resources::ClearMusic(){
	std::unordered_map<string, Mix_Music*>::iterator i;
	
	for(i = musicTable.begin(); i != musicTable.end(); i++){
			Mix_FreeMusic((*i).second);
	}
	musicTable.clear();
}


Mix_Chunk* Resources::GetSound(string file){
	const char *const_file = file.c_str();
	Game& game = Game::GetInstance();
	Mix_Chunk* sound;
	unordered_map< string, Mix_Chunk* >::const_iterator got = soundTable.find(file);
	
	//check if sound exist. yes?: return pointer  | no?: load and insert pair (path,ptr) on table
  	if ( got == soundTable.end() ){
    	//not found
    	sound = Mix_LoadWAV(const_file);
  		if (sound == nullptr)
			ErrorExit(__LINE__, Mix_GetError() ,__FILE__);

		soundTable.emplace(file, sound);
	}
  	else{
    	//Got it! got->first and got->second
    	sound = got->second;
  	}

	return sound;
}
void Resources::ClearSound(){
	std::unordered_map<string, Mix_Chunk*>::iterator i;
	
	for(i = soundTable.begin(); i != soundTable.end(); i++){
			Mix_FreeChunk((*i).second);
	}
	soundTable.clear();

}

TTF_Font* Resources::GetFont(){

}
void Resources::ClearFont(){

}