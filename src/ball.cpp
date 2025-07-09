#include "ball.hpp"
#include "vector.hpp"

Ball::Ball(float x, float y, float r) :
	x(x),
	y(y),
	radius(r),
	Polygon(50, r, x, y)
{
}

Ball::~Ball()
{
}

void Ball::set_color(float r, float g, float b, float a){
	for (int i = 0; i < n; i++){
		vertices[i].color = { r, g, b, a };
	}
}
