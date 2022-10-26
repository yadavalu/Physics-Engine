#include "RK4.h"

RK4::RK4(std::function<float(float, float)> dy_dx, float px, float py)
	: dy_dx(dy_dx)
{
	this->p[0] = px;
	this->p[1] = py;
}

RK4::~RK4()
{

}

float RK4::y(float x, float h, int max_n)
{
	float xn = p[0];
	float yn = p[1];
	float k1, k2, k3, k4;

	for (int i = 0; i < max_n; i++) {
		k1 = dy_dx(xn, yn);
		k2 = dy_dx(xn + h / 2, yn + h * k1 / 2);
		k3 = dy_dx(xn + h / 2, yn + h * k2 / 2);
		k4 = dy_dx(xn + h, yn + h * k3);
		xn += h;
		yn += (1 / 6) * (k1 + 2 * k2 + 2 * k3 + k4) * h;
	}
}


