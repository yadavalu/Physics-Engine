#include "Vector.h"

Vector2::Vector2()
{
}

Vector2::Vector2(float x, float y)
	: x(x), y(y)
{
}

Vector2::~Vector2()
{
}

float Vector2::GetXComponent() const
{
	return x;
}

float Vector2::GetYComponent() const
{
	return y;
}

float Vector2::GetMagnitude() const
{
	return sqrt(x * x + y * y);
}

Vector2 Vector2::Normalise() const
{
	// The following doesn't work
	//return (*this) / this->GetMagnitude();
	return Vector2(x, y) / this->GetMagnitude();
}

Vector2 Vector2::operator+(Vector2 rhs)
{
	return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 Vector2::operator+=(Vector2 rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Vector2 Vector2::operator+=(float rhs)
{
	x += rhs;
	y += rhs;
	return *this;
}

Vector2 Vector2::operator-(Vector2 rhs)
{
	return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 Vector2::operator-=(Vector2 rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

Vector2 Vector2::operator-=(float rhs)
{
	x -= rhs;
	y -= rhs;
	return *this;
}

float Vector2::operator*(Vector2 rhs)
{
	return x * rhs.x + y * rhs.y;
}

Vector2 Vector2::operator*(float rhs)
{
	return Vector2(rhs * x, rhs * y);
}

Vector2 operator*(float lhs, Vector2 vec)
{
	return Vector2(lhs * vec.x, lhs * vec.y);
}

Vector2 Vector2::operator%(Vector2 rhs)
{
	return Vector2(x * rhs.x, y * rhs.y);
}

Vector2 Vector2::operator/(float rhs)
{
	return Vector2(x / rhs, y / rhs);
}

Vector2 operator/(float lhs, Vector2 vec)
{
	return Vector2(lhs / vec.x, lhs / vec.y);
}

float Vector2::operator^(Vector2 rhs)
{
	float dot = *this * rhs;
	return dot / (this->GetMagnitude() * rhs.GetMagnitude());
}

std::ostream& operator<<(std::ostream& os, Vector2 vec)
{
	os << vec.x << ", " << vec.y;
	return os;
}


Vector3::Vector3()
{
}

Vector3::Vector3(Vector2 vec)
{
	x = vec.x;
	y = vec.y;
	z = 0;
}

Vector3::Vector3(float x, float y) {
	this->x = x;
	this->y = y;
	this->z = 0;
}

Vector3::Vector3(float x, float y, float z)
	: x(x), y(y), z(z)
{
}

Vector3::~Vector3()
{
}

float Vector3::GetXComponent() const
{
	return x;
}

float Vector3::GetYComponent() const
{
	return y;
}

float Vector3::GetZComponent() const
{
	return z;
}

float Vector3::GetMagnitude() const
{
	return sqrt(x * x + y * y + z * z);
}

Vector3 Vector3::Normalise() const
{
	// The following doesn't work
	//return (*this) / this->GetMagnitude();
	return Vector3(x, y, z) / this->GetMagnitude();
}

Vector3 Vector3::operator+(Vector3 rhs)
{
	return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vector3 Vector3::operator+=(Vector3 rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

Vector3 Vector3::operator+=(float rhs)
{
	x += rhs;
	y += rhs;
	z += rhs;
	return *this;
}

Vector3 Vector3::operator-(Vector3 rhs)
{
	return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
}

Vector3 Vector3::operator-=(Vector3 rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

Vector3 Vector3::operator-=(float rhs)
{
	x -= rhs;
	y -= rhs;
	z -= rhs;
	return *this;
}

float Vector3::operator*(Vector3 rhs)
{
	return x * rhs.x + y * rhs.y + z * rhs.z;
}

Vector3 Vector3::operator*(float rhs)
{
	return Vector3(rhs * x, rhs * y, rhs * z);
}

Vector3 operator*(float lhs, Vector3 vec) 
{
	return Vector3(lhs * vec.x, lhs * vec.y, lhs * vec.z);
}

Vector3 Vector3::operator%(Vector3 rhs)
{
	return Vector3(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
}

Vector3 Vector3::operator/(float rhs) 
{
	return Vector3(x / rhs, y / rhs, z / rhs);
}

Vector3 operator/(float lhs, Vector3 vec)
{
	return Vector3(lhs / vec.x, lhs / vec.y, lhs / vec.z);
}

float Vector3::operator^(Vector3 rhs)
{
	float dot = *this * rhs;
	return dot / (this->GetMagnitude() * rhs.GetMagnitude());
}

std::ostream& operator<<(std::ostream& os, Vector3 vec)
{
	os << vec.x << ", " << vec.y << ", " << vec.z;
	return os;
}

