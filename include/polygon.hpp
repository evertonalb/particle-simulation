#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <SDL3/SDL.h>

class Polygon {
protected:
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

	/// @brief Creates a regular polygon center at the origin based on the radius of the circumscribed circle.
	/// @param n number of vertices of the polygon.
	/// @param radius radius of the circumscribed circle.
	Polygon(int n, float radius);
	
	/// @brief Creates a regular polygon based on the radius of the circumscribed circle and a center.
	/// @param n number of vertices of the polygon.
	/// @param radius radius of the circumscribed circle.
	/// @param x x coordinate of the center
	/// @param y y  coordinate of the center
	Polygon(int n, float radius, float x, float y);

	void move(float dx, float dy);

	const SDL_Vertex *get_vertices() const;
	
	const int get_num_vertices() const;
	
	const int *get_indices() const;

	const int get_num_indices() const;

	~Polygon();
};


#endif // POLYGON_HPP