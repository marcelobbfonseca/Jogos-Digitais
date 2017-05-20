#ifndef ENDSTATE_H
#define ENDSTATE_H
#include "State.h"
#include "Sprite.h"
#include "Music.h"
#include "Text.h"
#include "StateData.h"

class EndState : public State
{
	public:
		EndState(StateData stateData);
		~EndState();
		
		void Update(float dt);
		void Render();
		void Pause();
		void Resume();	

	private:
		Sprite bg;
		Music music;
		Text instruction;
};

#endif