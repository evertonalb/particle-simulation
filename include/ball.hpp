#ifndef BALL_HPP
#define BALL_HPP

#include <SDL3/SDL.h>

class Ball {
private:
	float x, y, radius;
public:
	Ball(float x, float y, float r);
	~Ball();
};

#endif // BALL_HPP
