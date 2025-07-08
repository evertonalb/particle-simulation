#include "polygon.hpp"
#include "vector.hpp"

Polygon::Polygon(){}

Polygon::Polygon(int n, float radius) : n(n) {
	vertices = new SDL_Vertex[n];
	indices = new int[(n-2) * 3];
}

Polygon::~Polygon(){
	delete[] vertices;
	SDL_free(indices);
}
