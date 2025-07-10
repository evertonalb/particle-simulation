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

	move(dx, dy);
	
	// move(dx, dy);
	// SDL_Log("Ball position: (%f, %f)", x, y);
}

float Ball::lowest_x(){ return x - radius; }
float Ball::largest_x(){ return x + radius; }
float Ball::lowest_y(){ return y - radius; }
float Ball::largest_y(){ return y + radius; }

float Ball::get_radius() const { return radius; }
float Ball::get_x() const { return x; }
float Ball::get_y() const { return y; }

void Ball::move(float dx, float dy) {
	x += dx;
	y += dy;
	Polygon::move(dx, dy);
}


Vector Ball::get_speed_in_direction(float angle) const {
	Vector direction(SDL_cos(to_radians(angle)), SDL_sin(to_radians(angle)));
	float component;
	component = speed * direction;

	return component * direction;
}

bool Ball::is_colliding_with(const Ball &other) const{
	float dx = other.get_x() - get_x();
	float dy = other.get_y() - get_y();
	return SDL_sqrt(dx * dx + dy * dy) < (radius + other.get_radius());
}
