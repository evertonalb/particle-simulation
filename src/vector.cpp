#include "vector.hpp"

Vector::Vector(){}

Vector::Vector(float x, float y) : x(x), y(y) {}

Vector Vector::operator+(const Vector &v) const {
	Vector result;
	result.x = x + v.x;
	result.y = y + v.y;
	return result;
}

Vector Vector::operator+=(const Vector &v){
	*this = *this + v;
	return *this;
}

Vector Vector::operator-() const {
	Vector result;
	result.x = -x;
	result.y = -y;
	return result;
}

Vector Vector::operator-(const Vector &v) const { return (*this + (-v)); }

Vector Vector::operator-=(const Vector &v){
	*this = *this - v;
	return *this;
}

float Vector::operator*(const Vector &v) const { return x * v.x + y * v.y; }

Vector Vector::operator*(const float &c) const {
	Vector result;
	result.x = x * c;
	result.y = y * c;
	return result;
}

Vector Vector::operator*=(const float &c){
	*this = *this * c;
	return *this;
}

void Vector::rotate(float angle){
	angle = to_radians(angle);
	float newX = cos(angle) * x - sin(angle) * y;
	float newY = sin(angle) * x + cos(angle) * y;
	x = newX;
	y = newY;
}

Vector operator*(const float &c, const Vector &v){ return v * c; }
