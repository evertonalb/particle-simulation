#include "polygon.hpp"
#include "vector.hpp"

Polygon::Polygon(){}

Polygon::Polygon(const Polygon &other){
	n = other.n;
	numIndices = other.numIndices;

	vertices = new SDL_Vertex[n];
	for (int i = 0; i < n; i++){
		vertices[i] = other.vertices[i];
	}

	indices = new int[numIndices];
	for (int i = 0; i < numIndices; i++){
		indices[i] = other.indices[i];
	}
}

Polygon::Polygon(int n, float radius) : n(n), numIndices(3*(n-2)) {
	vertices = new SDL_Vertex[n];
	indices = new int[3*(n-2)];

	// Vertices
	Vector v(radius, 0);
	float angle = 360.0 / n;
	SDL_FColor white = {1.0, 1.0, 1.0, 1.0};
	for (int i = 0; i < n; i++){
		vertices[i].position.x = v.x;
		vertices[i].position.y = v.y;
		vertices[i].color = white;
		v.rotate(angle);
	}

	// Indices
	for (int i = 0; i < n-2; i++){
		indices[3*i + 0] = 0;
		indices[3*i + 1] = i + 1;
		indices[3*i + 2] = i + 2;
	}
	
}

Polygon::Polygon(int n, float radius, float x, float y) : Polygon(n, radius) { move(x, y); }

void Polygon::move(float dx, float dy)
{
	for (int i = 0; i < n; i++){
		vertices[i].position.x += dx;
		vertices[i].position.y += dy;
	}
}

const SDL_Vertex *Polygon::get_vertices() const { return vertices; }

const int Polygon::get_num_vertices() const { return n; }

const int *Polygon::get_indices() const { return indices; }

const int Polygon::get_num_indices() const { return numIndices; }

Polygon Polygon::operator=(const Polygon &other){
	if (this == &other) return *this; // Self-assignment check
	n = other.n;
	numIndices = other.numIndices;

	delete[] vertices;
	vertices = new SDL_Vertex[n];
	for (int i = 0; i < n; i++){
		vertices[i] = other.vertices[i];
	}

	delete[] indices;
	indices = new int[numIndices];
	for (int i = 0; i < numIndices; i++){
		indices[i] = other.indices[i];
	}

	return *this;
}

Polygon::~Polygon()
{
	delete[] vertices;
	delete[] indices;
}
