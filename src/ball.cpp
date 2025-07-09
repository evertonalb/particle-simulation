#include "ball.hpp"
#include "vector.hpp"

Ball::Ball(float x, float y, float r) :
	x(x),
	y(y),
	radius(r),
	Polygon(50, r, x, y)
{
	speed = Vector(250.0, 0.0);
	speed.rotate(SDL_randf() * 360.0); // Random initial direction
}

Ball::~Ball()
{
}

void Ball::set_color(float r, float g, float b, float a){
	for (int i = 0; i < n; i++){
		vertices[i].color = { r, g, b, a };
	}
}

void Ball::update(float &delta){
	float dx = speed.x * delta;
	float dy = speed.y * delta;

	x += dx;
	y += dy;
	move(dx, dy);
	
	// move(dx, dy);
	// SDL_Log("Ball position: (%f, %f)", x, y);
}

float Ball::lowest_x(){ return x - radius; }
float Ball::largest_x(){ return x + radius; }
float Ball::lowest_y(){ return y - radius; }
float Ball::largest_y(){ return y + radius; }