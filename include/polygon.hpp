#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <SDL3/SDL.h>

class Polygon {
private:
	/// @brief Number of vertices of the polygon.
	int n;

	/// @brief Pointer to the vertices of the polygon.
	SDL_Vertex *vertices = NULL;
	
	/// @brief Number of elements in the indices array.
	int numIndices;
	
	/// @brief Indicates the order to process the vertices in SDL_RenderGeometry()
	int *indices = NULL;
public:
	Polygon();

	/// @brief Creates a regular polygon based on the radius of the circumscribed circle.
	/// @param n number of vertices of the polygon.
	/// @param radius radius of the circumscribed circle.
	Polygon(int n, float radius);

	~Polygon();
};


#endif // POLYGON_HPP