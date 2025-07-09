#ifndef BALL_HPP
#define BALL_HPP

#include <SDL3/SDL.h>
#include "polygon.hpp"
#include "vector.hpp"

class Ball : public Polygon {
private:
	float x, y, radius;
	Vector speed; // Speed vector for the ball in pixels per second
public:
	Ball(float x, float y, float r);
	~Ball();
	void set_color(float r, float g, float b, float a);
	void update(float &delta);
};

#endif // BALL_HPP
