#ifndef BALL_HPP
#define BALL_HPP

#include <SDL3/SDL.h>
#include "polygon.hpp"

class Ball : public Polygon {
private:
	float x, y, radius;
public:
	Ball(float x, float y, float r);
	~Ball();
};

#endif // BALL_HPP
