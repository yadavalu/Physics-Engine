#include "System.h"

#include <iostream>

System::System(Vector3 gravity, int width, int height, bool flipcoordinates)
	: gravity(gravity), width(width), height(height), flip(flipcoordinates)
{
}

System::~System()
{
}

void System::AddObject(Object* obj)
{
	objs.push_back(obj);
}

void System::RemoveObject(Object* obj)
{
	remove(objs.begin(), objs.end(), obj);
}

void System::AddRigidObject(RigidObject* robj)
{
	robjs.push_back(robj);
}

void System::RemoveRigidObject(RigidObject* robj)
{
	remove(robjs.begin(), robjs.end(), robj);
}

std::vector<Object*> System::GetObjects() const
{
	return objs;
}

void System::Step(float dt)
{
	for (RigidObject*& robj : robjs) {
		robj->force += robj->mass * gravity;
		robj->velocity += robj->force / robj->mass * dt;
		robj->position += robj->velocity * dt;
		robj->force = Vector3(0, 0, 0);

		for (Object*& obj : objs) {
			if (!obj->hitting) {
				obj->force += obj->mass * gravity + obj->mass * robj->gravity;
				obj->velocity += obj->force / obj->mass * dt;
				obj->position += obj->velocity * dt;
				obj->force = Vector3(0, 0, 0);

				// Constrains
				if (robj->position.x <= obj->position.x + obj->size.x && obj->position.x <= robj->position.x + robj->size.x) {
					if (robj->position.y <= obj->position.y + obj->size.y && obj->position.y <= robj->position.y + robj->size.y) {
						obj->hitting = true;
					}
				}
			}
			else {
				if (robj->position.x > obj->position.x + obj->size.x && obj->position.x > robj->position.x + robj->size.x) {
					if (robj->position.y > obj->position.y + obj->size.y && obj->position.y > robj->position.y + robj->size.y) {
						obj->hitting = false;
					}
				}
			}
		}
	}	
}

void System::ResolveCollisions()
{
	Object* curr;
	Object* next;

	// O(n^2)
	for (int i = 0; i < objs.size(); i++) {
		curr = objs[i];
		for (int j = i + 1; j < objs.size(); j++) {
			next = objs[j];
			Vector3 dist = curr->position - next->position;
			float approxrad = sqrt(curr->size.x * curr->size.x + curr->size.y * curr->size.y);
			if (dist.GetMagnitude() < approxrad) {
				Vector3 normal = dist.Normalise();
				float delta = approxrad - dist.GetMagnitude();

				curr->position += 0.5 * delta * normal;
				next->position -= 0.5 * delta * normal;

				float c1 = (curr->mass - next->mass) / (curr->mass + next->mass);
				float c2 = 2 / (curr->mass + next->mass);
				curr->velocity = c1 * curr->velocity + c2 * next->mass * next->velocity;
				next->velocity = c2 * curr->mass * curr->velocity - c1 * next->velocity;
			}
		}
	}
}
