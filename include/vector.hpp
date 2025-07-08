#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cmath>

class Vector {
private:
public:
	float x, y;

	Vector();	
	Vector(float x, float y);	
	Vector operator+(Vector v);
	Vector operator+=(Vector v);
	Vector operator-();
	Vector operator-(Vector v);
	Vector operator-=(Vector v);
	Vector operator*(float c);
	Vector operator*=(float c);
};

Vector operator*(float c, Vector v);

#endif