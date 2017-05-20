
#ifndef MUSIC_H
#define MUSIC_H
#include "SDL2/SDL_mixer.h"
#include <string>
using std::string;

class Music
{
	public:
		Music();
		Music(string file);
		~Music();

		void Play(int _times);
		void Stop();
		void Open(string file);
		bool IsOpen();
	private:
		Mix_Music* music;	

};

#endif