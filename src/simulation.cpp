#include "simulation.hpp"

Simulation::Simulation(const char *title, int w, int h){
	window = SDL_CreateWindow(title, w, h, SDL_WINDOW_MAXIMIZED);
}

Simulation::~Simulation(){
	SDL_DestroyWindow(window);
}
