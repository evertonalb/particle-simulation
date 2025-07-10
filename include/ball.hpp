#ifndef BALL_HPP
#define BALL_HPP

#include <SDL3/SDL.h>
#include "polygon.hpp"
#include "vector.hpp"

class Ball : public Polygon {
private:
	float x, y, radius;
public:
	Vector speed; // Speed vector for the ball in pixels per second

	Ball(float x, float y, float r);
	~Ball();
	void set_color(float r, float g, float b, float a);
	void update(float &delta);
	float lowest_x();
	float largest_x();
	float lowest_y();
	float largest_y();
	float get_radius() const;
	float get_x() const;
	float get_y() const;
	void move(float dx, float dy);
};

#endif // BALL_HPP
