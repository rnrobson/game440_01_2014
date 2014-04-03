// Vector3 Class - AI/Nav Depends On This
// Josh O'Donnell
// April 2014

#ifndef _VEC3F_H
#define _VEC3F_H

#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

const float PI = 3.14159265359f;

class Vec3f {
private:

protected:
public:
	Vec3f();
	Vec3f(const float x, const float y);
	Vec3f(const float x, const float y, const float z);
	~Vec3f();

	static Vec3f Zero();

	void Normalize();
	void ComputePolarCoords();
	void ComputeCartesianCoords();
	void SetLength(float length);
	void SetValues(const float x, const float y, const float z);

	Vec3f Cross(const Vec3f vec) const;
	Vec3f Lerp(const Vec3f vec, const float interpFactor) const;
	Vec3f ProjectionOnto(Vec3f vec);

	float Dot(const Vec3f vec) const;
	float Length() const;

	std::string ToString();

	static void OrthoNormalize(Vec3f& xVec, Vec3f& yVec, Vec3f& zVec);

	Vec3f operator+(const Vec3f& vec);
	void operator+=(const Vec3f& vec);

	Vec3f operator-(const Vec3f& vec);
	friend Vec3f operator-(const Vec3f& lhs, const Vec3f& rhs);
	Vec3f operator-(const float scalar);
	void operator-=(const Vec3f& vec);

	Vec3f operator*(const Vec3f& vec);
	Vec3f operator*(const float scalar);
	void operator*=(const Vec3f& vec);
	void operator*=(const float scalar);

	Vec3f operator/(const Vec3f& vec);
	Vec3f operator/(const float scalar);
	void operator/=(const Vec3f& vec);

	bool operator==(const Vec3f& vec);
	bool operator!=(const Vec3f& vec);

	float x;
	float y;
	float z;

	float phi;
	float theta;
};

#endif