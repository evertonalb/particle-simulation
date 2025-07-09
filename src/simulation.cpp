#include "simulation.hpp"

void Simulation::handle_events(){
	SDL_Event event;
	// Poll events until there are no more events in the queue
	while (SDL_PollEvent(&event)){
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
}

void Simulation::passTime(float &delta){
	lastTime = currentTime;
	SDL_GetCurrentTime(&currentTime);
	delta = (currentTime - lastTime) / 1e9f; // Convert nanoseconds to seconds
}

void Simulation::draw(){
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	for (const auto &ball : balls){
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderGeometry(
			renderer,
			NULL,
			ball.get_vertices(),
			ball.get_num_vertices(),
			ball.get_indices(),
			ball.get_num_indices()
		);
	}

	SDL_RenderPresent(renderer);
}

void Simulation::create_ball(float r, float g, float b, float a){
	int w, h;
	SDL_GetWindowSizeInPixels(window, &w, &h);
	balls.emplace_back(w / 2.0, h / 2.0, 50);
	balls.back().set_color(r, g, b, a);
}

Simulation::Simulation(const char *title, int w, int h){
	window = SDL_CreateWindow(title, w, h, SDL_WINDOW_MAXIMIZED);
	renderer = SDL_CreateRenderer(window, NULL);
}

void Simulation::run(){
	running = true;

	create_ball(0, 0.7, 0.7, 1.0);

	float delta;
	SDL_Event event;
	while (running){
		handle_events();
		passTime(delta);
		draw();
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
