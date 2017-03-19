#include "Sprite.h"

#ifndef MEUPROJETO_STATE_H
#define MEUPROJETO_STATE_H

class State
{
public:
	State();
	~State();

	bool QuitRequested();
	void LoadAssets();
	void Update(float);
	void Render();
	
private:
	Sprite bg;
	bool quitRequested;
};

#endif