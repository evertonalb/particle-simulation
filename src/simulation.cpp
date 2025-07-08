#include "simulation.hpp"

void Simulation::handle_event(SDL_Event event){
	switch (event.type){
	case SDL_EVENT_QUIT:
		running = false;
		break;
	
	case SDL_EVENT_KEY_DOWN:
		on_key_press(event.key);
		break;
		
	default:
		break;
	}
}

Simulation::Simulation(const char *title, int w, int h){
	window = SDL_CreateWindow(title, w, h, SDL_WINDOW_MAXIMIZED);
}

void Simulation::run(){
	running = true;

	SDL_Event event;
	while (running){
		while (SDL_PollEvent(&event))
			handle_event(event);
	}	
}

void Simulation::on_key_press(SDL_KeyboardEvent keyboardEvent){
	SDL_Event custom;
	
	switch (keyboardEvent.key){
	case SDLK_ESCAPE:
		custom.type = SDL_EVENT_QUIT;
		SDL_PushEvent(&custom);
		break;

	default:
		break;
	}
}

Simulation::~Simulation(){
	SDL_DestroyWindow(window);
}
