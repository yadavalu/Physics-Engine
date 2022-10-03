#pragma once

#include <vector>

#include "Vector.h"
#include "Object.h"

class System
{
public:
	System(Vector3 gravity, int width, int height, bool flipcoordinates = false);
	~System();
	
	void AddObject(Object* obj);
	void RemoveObject(Object* obj);

	void AddRigidObject(RigidObject* robj);
	void RemoveRigidObject(RigidObject* robj);

	std::vector<Object*> GetObjects() const;

	void Step(float dt);
	void ResolveCollisions();

	std::vector<Object*> objs;
	std::vector<RigidObject*> robjs;

private:
	std::vector<Vector2> boundries;

	int width, height;
	bool flip = false;

	Vector3 gravity;
};

