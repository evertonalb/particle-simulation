#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <SDL3/SDL.h>
#include "ball.hpp"

class Simulation {
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	bool running;

	void handle_event(SDL_Event event);
	void draw();
public:
	Simulation(const char *title, int w, int h);

	void run();
	void on_key_press(SDL_KeyboardEvent keyboardEvent);
	
	~Simulation();
};

#endif // SIMULATION_HPP