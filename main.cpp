#include "simulation.hpp"
#include <SDL3/SDL_main.h>

using namespace std;
int SDL_main(int argc, char **args){ 
	SDL_Init(SDL_INIT_VIDEO);

	Simulation sim("Simulation", 600, 800);

	SDL_Quit();
	return 0;
}