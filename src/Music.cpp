#include "Music.h"
#include "Resources.h"
Music::Music(){
	music = nullptr;
}
Music::Music(string file){
	Open(file);
}
Music::~Music(){

}


void Music::Play(int _times){
	Mix_PlayMusic(music, _times); // -1 para loopar musica
}
void Music::Stop(){
	Mix_FadeOutMusic(1200 /*milisecounds*/);
}
void Music::Open(string file){
	printf("passou aqui\n");
	music = Resources::GetMusic(file);
	std::cout << music << std::endl;
	printf("pegou musica!\n");
}
bool Music::IsOpen(){
	if (music != nullptr)
		return true;
	else
		return false;
}