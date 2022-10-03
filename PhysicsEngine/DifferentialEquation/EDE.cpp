#include "EDE.h"
#include "Debug.h"

EDE::EDE(std::function<float(float, float)> dy_dx, float px, float py)
	: dy_dx(dy_dx)
{
	this->p[0] = px;
	this->p[1] = py;
}

EDE::~EDE()
{
}

float EDE::y(float x, float del_x)
{
	float _x = p[0], _y = p[1];
	float dir = _x < x ? 1 : -1;

	while (_x != x) {
		_y = _y + dy_dx(_x, _y) * del_x;
		_x += dir * del_x;
		//DEBUG(_x);
		//DEBUG(_y);
	}

	return _y;
}
