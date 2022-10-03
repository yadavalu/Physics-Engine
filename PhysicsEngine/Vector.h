#pragma once

#include <math.h>
#include <ostream>

class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	~Vector2();

	float GetXComponent() const;
	float GetYComponent() const;
	float GetMagnitude() const;
	Vector2 Normalise() const;

	Vector2 operator+(Vector2 rhs);  // Add vectors
	Vector2 operator+=(Vector2 rhs);
	Vector2 operator+=(float rhs);
	Vector2 operator-(Vector2 rhs);  // Subtract vectors
	Vector2 operator-=(Vector2 rhs);
	Vector2 operator-=(float rhs);
	float operator*(Vector2 rhs);  // Dot product
	Vector2 operator*(float rhs);  // Scalar multiplication
	friend Vector2 operator*(float lhs, Vector2 vec);  // Scalar multiplication
	Vector2 operator%(Vector2 rhs);  // Cross product
	Vector2 operator/(float rhs);
	friend Vector2 operator/(float lhs, Vector2 vec);
	float operator^(Vector2 rhs);  // Get angle
	friend std::ostream& operator<<(std::ostream& os, Vector2 vec);

public:
	float x, y;

private:
};

class Vector3
{
public:
	Vector3();
	Vector3(Vector2 vec);
	Vector3(float x, float y);
	Vector3(float x, float y, float z);
	~Vector3();

	float GetXComponent() const;
	float GetYComponent() const;
	float GetZComponent() const;
	float GetMagnitude() const;
	Vector3 Normalise() const;

	Vector3 operator+(Vector3 rhs);  // Add vectors
	Vector3 operator+=(Vector3 rhs);
	Vector3 operator+=(float rhs);
	Vector3 operator-(Vector3 rhs);  // Subtract vectors
	Vector3 operator-=(Vector3 rhs);
	Vector3 operator-=(float rhs);
	float operator*(Vector3 rhs);  // Dot product
	Vector3 operator*(float rhs);  // Scalar multiplication
	friend Vector3 operator*(float lhs, Vector3 vec);  // Scalar multiplication
	Vector3 operator%(Vector3 rhs);  // Cross product
	Vector3 operator/(float rhs);
	friend Vector3 operator/(float lhs, Vector3 vec);
	float operator^(Vector3 rhs);  // Get angle
	friend std::ostream& operator<<(std::ostream& os, Vector3 vec);

public:
	float x, y, z;

private:
};


