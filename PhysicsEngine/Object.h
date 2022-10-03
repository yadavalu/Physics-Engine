#pragma once

#include "Vector.h"


struct Object 
{
	Object(Vector3 position, Vector3 velocity, Vector3 force, float mass)
		: position(position), velocity(velocity), force(force), mass(mass) {}

	void SetSize(Vector2 size) { this->size = size; }

	Vector3 position;
	Vector3 velocity;
	Vector3 force;
	float mass;

	Vector2 size;
	bool hitting = false;
};

// Inheritance not working
struct RigidObject
{
	RigidObject(Vector3 position, Vector3 velocity, Vector3 force, float mass, Vector3 gravity, float staticfriction, float dynamicfriction, float elasticity)
		: position(position), velocity(velocity), force(force), mass(mass), gravity(gravity), staticfriction(staticfriction), dynamicfriction(dynamicfriction), elasticity(elasticity)
	{}

	Vector3 position;
	Vector3 velocity;
	Vector3 force;
	float mass;

	void SetSize(Vector2 size) { this->size = size; }

	Vector2 size;

	Vector3 gravity;

	float staticfriction;
	float dynamicfriction;
	float elasticity;
};

