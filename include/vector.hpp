#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cmath>
#include <SDL3/SDL.h>
#define to_radians(x) x * M_PI / 180.0

class Vector : public SDL_FPoint {
private:
public:
	float x, y;

	Vector();	
	Vector(float x, float y);	


	// Linear operators

	Vector operator+(Vector v);
	Vector operator+=(Vector v);
	Vector operator-();
	Vector operator-(Vector v);
	Vector operator-=(Vector v);
	// Dot product
	float operator*(Vector v);
	Vector operator*(float c);
	Vector operator*=(float c);

	
	/// @brief Rotates the vector counterclockwise
	/// @param angle The angle of rotation in degrees 
	void rotate(float angle);
};

Vector operator*(float c, Vector v);

#endif