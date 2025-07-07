#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <SDL3/SDL.h>

class Simulation {
private:
	SDL_Window *window;
public:
	Simulation(const char *title, int w, int h);
	
	~Simulation();
};

#endif // SIMULATION_HPP