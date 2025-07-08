#include "polygon.hpp"
#include "vector.hpp"

Polygon::Polygon(){}

Polygon::Polygon(int n, float radius) : n(n), numIndices(3*(n-2)) {
	vertices = new SDL_Vertex[n];
	indices = new int[3*(n-2)];

	// Vertices
	Vector v(radius, 0);
	float angle = 360.0 / n;
	for (int i = 0; i < n; i++){
		vertices[i].position = v;
		v.rotate(angle);
	}

	// Indices
	for (int i = 0; i < n-2; i++){
		indices[3*i + 0] = 0;
		indices[3*i + 1] = i + 1;
		indices[3*i + 2] = i + 2;
	}
	
}

Polygon::~Polygon(){
	delete[] vertices;
	SDL_free(indices);
}
