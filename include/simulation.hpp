#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <SDL3/SDL.h>

class Simulation {
private:
	SDL_Window *window;
	bool running;

	void handle_event(SDL_Event event);
public:
	Simulation(const char *title, int w, int h);

	void run();
	void on_key_press(SDL_KeyboardEvent keyboardEvent);
	
	~Simulation();
};

#endif // SIMULATION_HPP