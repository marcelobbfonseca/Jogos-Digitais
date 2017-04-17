#include "Vec2.h"

Vec2::Vec2(){

}
Vec2::Vec2(float x, float y){
	this->x = x;
	this->y = y;
}

Vec2 Vec2::operator+(Vec2 const &b)const{

	return Vec2(x+b.x, y+b.y);

}

Vec2 Vec2::operator-(Vec2 const &b) const{

	return Vec2(x-b.x, y-b.y);

}
Vec2 Vec2::operator*(float b) const
{
	return Vec2(x*b, y*b);
}

Vec2::~Vec2(){

}