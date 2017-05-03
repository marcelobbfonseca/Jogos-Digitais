#include "Rect.h"

Rect::Rect(){
	this->x = 0;
	this->y = 0;
	this->w = 0;
	this->h = 0;
}

Rect::Rect(float x, float y, float w, float h){
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}
Rect::operator SDL_Rect() const{
	SDL_Rect rect;
	rect.x = this->x;
	rect.y = this->y;
	rect.w = this->w;
	rect.h = this->h;

	return rect;
}
Rect::operator Vec2 () const{
	return Vec2(x,y);
}
Rect Rect::operator+(Vec2 const &a) const{
	return Rect(a.x + this->x, a.y + this->y, this->w, this->h);
}
Rect Rect::operator-(Vec2 const &a) const{
	return Rect(a.x - this->x, a.y - this->y, this->w, this->h); 
}
Rect Rect::operator=(Vec2 const &a){
	this->x = a.x;
	this->y = a.y;

	return *this;
}
Vec2 Rect::Center() const{
	return Vec2(x+(w/2.0), y+(h/2.0) );
}
Rect::~Rect(){
	
}
