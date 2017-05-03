#ifndef RECT_H
#define RECT_H

#include "Vec2.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//representa uma posicao no quadro da tela. X,Y canto superior esquerdo
class Rect
{
public:
	Rect();
	Rect(float x, float y, float w, float h);
	operator SDL_Rect() const;
	operator Vec2 () const;
	Rect operator+(Vec2 const &a) const;
	Rect operator-(Vec2 const &a) const;
	Rect operator=(Vec2 const &a);
	Vec2 Center() const;	
	~Rect();
	
	float x, y, w, h;

	
};


#endif