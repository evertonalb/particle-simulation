#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <SDL3/SDL.h>

class Simulation {
private:
	SDL_Window *window;
	bool running;
public:
	Simulation(const char *title, int w, int h);

	void run();
	
	~Simulation();
};

#endif // SIMULATION_HPP