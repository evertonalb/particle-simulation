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
