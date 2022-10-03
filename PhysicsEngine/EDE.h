#pragma once

// Eulers method Differential Equation solver

#include <functional>

class EDE
{
public:
	EDE(std::function<float(float, float)> dy_dx, float px, float py);
	~EDE();

	float y(float x, float del_x = 0.001);

private:
	std::function<float(float, float)> dy_dx;
	float p[2];
};

