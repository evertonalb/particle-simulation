#include "ball.hpp"
#include "vector.hpp"
#include <stdexcept>

// Ball class implementation

Ball::Ball(float x, float y, float r) :
	x(x),
	y(y),
	radius(r),
	Polygon(50, r, x, y)
{
	speed = Vector(250.0, 0.0);
	speed.rotate(SDL_randf() * 360.0); // Random initial direction
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

float Ball::lowest_x() const { return x - radius; }
float Ball::largest_x() const { return x + radius; }
float Ball::lowest_y() const { return y - radius; }
float Ball::largest_y() const { return y + radius; }

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

bool Ball::is_colliding_with(const Ball &other) const {
	if (this == &other) return false; // No collision with itself
	float dx = other.get_x() - get_x();
	float dy = other.get_y() - get_y();
	return SDL_sqrt(dx * dx + dy * dy) < (radius + other.get_radius());
}

// Edge class implementation

Edge::Edge(const Edge &other) : parent(other.parent), direction(other.direction) {}

Edge::Edge(Ball *parent, EdgeDirection direction) : parent(parent), direction(direction) {}

Edge Edge::operator=(const Edge &other){
	if (this == &other) return *this; // Handle self-assignment
	direction = other.direction;
	parent = other.parent; // Copy the parent ball pointer
	return *this;
}

float Edge::get_x() const {
	if (direction == LEFT) {
		return parent->lowest_x();
	} else if (direction == RIGHT) {
		return parent->largest_x();
	} else throw std::runtime_error("Edge::get_x() called on an invalid direction");
}

float Edge::get_y() const {
	if (direction == TOP) {
		return parent->lowest_y();
	} else if (direction == BOTTOM) {
		return parent->largest_y();
	} else throw std::runtime_error("Edge::get_y() called on an invalid direction");
}

EdgeDirection Edge::get_direction() const { return direction; }
