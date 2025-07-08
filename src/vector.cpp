#include "vector.hpp"

Vector::Vector(){}

Vector::Vector(float x, float y) : x(x), y(y) {}

Vector Vector::operator+(Vector v){
	Vector result;
	result.x = x + v.x;
	result.y = y + v.y;
	return result;
}

Vector Vector::operator+=(Vector v){
	*this = *this + v;
	return *this;
}

Vector Vector::operator-(){
	Vector result;
	result.x = -x;
	result.y = -y;
	return result;
}

Vector Vector::operator-(Vector v){ return (*this + (-v)); }

Vector Vector::operator-=(Vector v){
	*this = *this - v;
	return *this;
}

Vector Vector::operator*(float c){
	Vector result;
	result.x = x * c;
	result.y = y * c;
	return result;
}

Vector Vector::operator*=(float c){
	*this = *this * c;
	return *this;
}

Vector operator*(float c,  Vector v){ return v * c; }
