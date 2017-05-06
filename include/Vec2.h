

#ifndef VEC2_H
#define VEC2_H

#include <cmath>

//expressa um vetor no R2, que pode tanto representar uma posição no espaço como uma grandeza.
class Vec2
{
public:
	Vec2();
	Vec2(float x, float y);
	float x, y;

	float Magnitude();
	void Normalize();
	float Distance(Vec2 const &vet) const;
	Vec2 Rotate(float angle) const;
	float InclineVet() const;

	Vec2 operator+(Vec2 const &b) const;
	Vec2 operator-(Vec2 const &b) const;
	Vec2 operator*(float b) const;
	~Vec2();

};

#endif