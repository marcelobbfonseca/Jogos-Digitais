#include "Vec2.h"

Vec2::Vec2(){
	this->x = 0.0;
	this->y = 0.0;
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

Vec2 Vec2::operator*(float b) const{
	return Vec2(x*b, y*b);
}

float Vec2::Magnitude(){
	float magnitude = sqrt( (x * x) + (y * y) );
	return magnitude;
}

float Vec2::Distance(Vec2 const &vet) const{
	return ((*this)-vet).Magnitude();
}

void Vec2::Normalize(){
	float norm= Magnitude();
	x=x/norm;
	y=y/norm;
}

Vec2 Vec2::Rotate(float angle) const{
	float xNew, yNew;
	xNew = x*cos(angle)-y*sin(angle);
	yNew = y*cos(angle)+x*sin(angle);
	return Vec2(xNew, yNew);
}

float Vec2::InclineVet() const{ //in radians
	return (float)atan2(y, x);
}


Vec2::~Vec2(){

}
