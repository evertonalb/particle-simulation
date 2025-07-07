#include "simulation.hpp"

Simulation::Simulation(const char *title, int w, int h) {
	window = SDL_CreateWindow(title, w, h, SDL_WINDOW_MAXIMIZED);
}

void Simulation::run(){
	running = true;

	SDL_Event event;
	while (running){
		while (SDL_PollEvent(&event)){
			switch (event.type){
			case SDL_EVENT_QUIT:
				running = false;
				break;
			
			default:
				break;
			}
		}
	}
}

Simulation::~Simulation(){
	SDL_DestroyWindow(window);
}
