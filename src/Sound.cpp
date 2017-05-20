#include "Sound.h"
#include "Resources.h"

Sound::Sound(){
	chunk = nullptr;
}

Sound::Sound(string file){
	Open(file);
}
Sound::~Sound(){

}

void Sound::Play(int _times){
	channel= Mix_PlayChannel(-1, chunk, _times); //-1
}
void Sound::Stop(){
	Mix_HaltChannel(channel);
}

void Sound::Open(string file){
	chunk = Resources::GetSound(file);
}

bool Sound::IsOpen(){
	if (chunk != nullptr)
		return true;
	else
		return false;
}
