#ifndef BALL_HPP
#define BALL_HPP

#include <SDL3/SDL.h>
#include "polygon.hpp"
#include "vector.hpp"

class Edge; // Forward declaration for Edge class

class Ball : public Polygon {
private:
	float x, y, radius;
public:
	Vector speed; // Speed vector for the ball in pixels per second

	Ball(float x, float y, float r);
	void set_color(float r, float g, float b, float a);
	void update(float &delta);
	float lowest_x() const;
	float largest_x() const;
	float lowest_y() const;
	float largest_y() const;
	float get_radius() const;
	float get_x() const;
	float get_y() const;
	void move(float dx, float dy);
	
	/// @brief Returns the speed component in the direction of the given angle.
	/// @details The angle is in degrees, where 0 degrees is to the right (positive x-axis).
	/// @param angle The angle in degrees.
	/// @return The speed component in the direction of the angle.
	Vector get_speed_in_direction(float angle) const;
	bool is_colliding_with(const Ball &other) const;

	friend class Edge;
};

typedef enum {LEFT, RIGHT} EdgeDirection;

class Edge {
private:
	EdgeDirection direction;
	
public:
	Ball *parent;

	Edge() = default;
	Edge(const Edge &other);
	Edge(Ball *parent, EdgeDirection direction);
	Edge operator=(const Edge &other);
	float get_x() const;
	EdgeDirection get_direction() const;

	~Edge() = default;
};

#endif // BALL_HPP
