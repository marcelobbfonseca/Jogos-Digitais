
#ifndef SOUND_H
#define SOUND_H
#include "SDL2/SDL_mixer.h"
#include <string>
using std::string;

class Sound
{
	public:
		Sound();
		Sound(string file);
		~Sound();
		
		void Play(int _times);
		void Stop();
		void Open(string file);
		bool IsOpen();
	private:
		Mix_Chunk* chunk;
		int channel;
};

#endif