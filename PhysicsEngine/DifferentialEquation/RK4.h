#pragma once

#include <functional>

class RK4
{
public:
	RK4(std::function<float(float, float)> dy_dx, float px, float py);
	~RK4();

	float y(float x, float del_x = 0.001, int max_n = 100);

private:
	std::function<float(float, float)> dy_dx;
	float p[2];
};

