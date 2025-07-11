#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <SDL3/SDL.h>
#include <vector>
#include "ball.hpp"

class Simulation {
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	bool running;
	std::vector<Ball> balls;
	float radius = 10;
	SDL_Time currentTime, lastTime; // Current and last time in nanoseconds
	
	void handle_events();
	void passTime(float &delta);
	void update(float &delta);
	void draw();
	void create_ball(float r, float g, float b, float a, float x, float y);
	void create_balls(int n);
	void window_collision(Ball &ball);
	void resolve_collision(Ball &ball1, Ball &ball2);
public:
	Simulation(const char *title, int w, int h);

	void run();
	void on_key_press(SDL_KeyboardEvent keyboardEvent);
	
	~Simulation();
};

#endif // SIMULATION_HPP