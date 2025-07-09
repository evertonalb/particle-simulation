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
	
	void handle_event(SDL_Event event);
	void draw();
	void createBall(float r, float g, float b, float a);
public:
	Simulation(const char *title, int w, int h);

	void run();
	void on_key_press(SDL_KeyboardEvent keyboardEvent);
	
	~Simulation();
};

#endif // SIMULATION_HPP