#include "simulation.hpp"
#include <SDL3/SDL_main.h>

using namespace std;
int SDL_main(int argc, char **args){ 
	SDL_Init(SDL_INIT_VIDEO);

	Simulation sim("Simulation", 1000, 1000);

	sim.run();
	
	SDL_Quit();
	return 0;
}