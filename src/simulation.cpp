#include "simulation.hpp"
#include <algorithm>


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

		case SDL_EVENT_WINDOW_MOVED:
			SDL_GetCurrentTime(&currentTime); // Reset current time
			lastTime = currentTime; // Reset last time
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
	if (delta > 0.05) delta = 0.016;
}
	
void Simulation::update(float &delta){
	
	for (auto ball : balls){
		ball->update(delta);
		window_collision(*ball);
	}

	// Check for collisions between balls
	std::sort(edgesX.begin(), edgesX.end(), [](const Edge &a, const Edge &b) {
		return a.get_x() < b.get_x();
	});

	std::set<Ball *> overlapping; // Set to track overlapping balls

	for (const auto &edge : edgesX) {
		if (edge.get_direction() == LEFT){
			overlapping.insert(edge.parent);

			Ball &current = *edge.parent;
			for (auto other : overlapping) {
				if (other == &current) continue; // Skip self-collision
				overlapsX[current.id][other->id] = true;
				overlapsX[other->id][current.id] = true;
			}
		} else if (edge.get_direction() == RIGHT){
			overlapping.erase(edge.parent);
		}
	}

	std::sort(edgesY.begin(), edgesY.end(), [](const Edge &a, const Edge &b) {
		return a.get_y() < b.get_y();
	});

	for (const auto &edge : edgesY) {
		if (edge.get_direction() == TOP){
			overlapping.insert(edge.parent);

			Ball &current = *edge.parent;
			for (auto other : overlapping) {
				if (other == &current || !overlapsX[current.id][other->id]) continue; // Skip self-collision and already ruled out collisions

				// Check for collision with the current ball				
				if (current.is_colliding_with(*other)) {
					resolve_collision(current, *other);
				}
			}
		} else if (edge.get_direction() == BOTTOM){
			overlapping.erase(edge.parent);
		}
	}

	// Reset overlapsX for the next frame
	for (auto &row : overlapsX) {
		std::fill(row.begin(), row.end(), false);
	}

	SDL_Delay(16); // Limit frame rate to approximately 60 FPS
}

void Simulation::draw(){
	for (const auto ball : balls){
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderGeometry(
			renderer,
			NULL,
			ball->get_vertices(),
			ball->get_num_vertices(),
			ball->get_indices(),
			ball->get_num_indices()
		);
	}

	SDL_RenderPresent(renderer);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void Simulation::create_ball(float r, float g, float b, float a, float x, float y){
	balls.push_back(new Ball(x, y, radius));
	balls.back()->set_color(r, g, b, a);
}

void Simulation::create_balls(int n){
	int w, h;
	SDL_GetWindowSizeInPixels(window, &w, &h);
	for (int i = 0; i < n; i++){
		create_ball(
			0.1 + 0.8 * SDL_randf(),
			0.1 + 0.8 * SDL_randf(),
			0.1 + 0.8 * SDL_randf(),
			1.0,
			radius + SDL_randf() * (w - 2 * radius),
			radius + SDL_randf() * (h - 2 * radius)
		);
		balls.back()->id = i;
		edgesX.push_back(Edge(balls.back(), LEFT));
		edgesX.push_back(Edge(balls.back(), RIGHT));
		edgesY.push_back(Edge(balls.back(), TOP));
		edgesY.push_back(Edge(balls.back(), BOTTOM));
		overlapsX = std::vector< std::vector<bool> >(n, std::vector<bool>(n, false));
	}

}

void Simulation::window_collision(Ball &ball){
	// Handles collisions with the window boundaries
	int w, h;
	SDL_GetWindowSizeInPixels(window, &w, &h);
	
	if (ball.lowest_x() < 0){
		ball.speed.x = -ball.speed.x; // Reverse horizontal speed
		ball.move(-ball.lowest_x(), 0); // Move ball to the right
	} else if (ball.largest_x() > w){
		ball.speed.x = -ball.speed.x; // Reverse horizontal speed
		ball.move(-ball.largest_x() + w, 0); // Move ball to the left
	}

	if (ball.lowest_y() < 0){
		ball.speed.y = -ball.speed.y; // Reverse vertical speed
		ball.move(0, -ball.lowest_y()); // Move ball down
	} else if (ball.largest_y() > h){
		ball.speed.y = -ball.speed.y; // Reverse vertical speed
		ball.move(0, -ball.largest_y() + h); // Move ball up
	}
}

void Simulation::resolve_collision(Ball &ball1, Ball &ball2){
	float dx = ball2.get_x() - ball1.get_x();
	float dy = ball2.get_y() - ball1.get_y();
	float angle = SDL_atan2f(dy, dx);

	Vector normalSpeed1 = ball1.get_speed_in_direction(angle * 180 / SDL_PI_F);
	Vector normalSpeed2 = ball2.get_speed_in_direction(angle * 180 / SDL_PI_F);


	ball1.speed -= normalSpeed1;
	ball2.speed -= normalSpeed2;
	ball1.speed += normalSpeed2;
	ball2.speed += normalSpeed1;

	// Move balls apart
	float overlap = (ball1.get_radius() + ball2.get_radius()) - SDL_sqrtf(dx * dx + dy * dy);
	Vector moveVector = Vector(SDL_cosf(angle), SDL_sinf(angle)) * overlap * 0.5f; // Move each ball half the overlap distance
	ball1.move(-moveVector.x, -moveVector.y);
	ball2.move(moveVector.x, moveVector.y);
}

Simulation::Simulation(const char *title, int w, int h){
	window = SDL_CreateWindow(title, w, h, SDL_WINDOW_MAXIMIZED);
	renderer = SDL_CreateRenderer(window, NULL);

	// Random seed initialization
	SDL_Time time;
	SDL_GetCurrentTime(&time);
	SDL_srand(time);
}

void Simulation::run(){
	running = true;

	create_balls(100);
	
	float delta;
	SDL_Event event;
	SDL_GetCurrentTime(&currentTime);
	while (running){
		passTime(delta);
		handle_events();
		update(delta);
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
