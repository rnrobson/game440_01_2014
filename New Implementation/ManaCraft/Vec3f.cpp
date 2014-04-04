// Vector3 Class - AI/Nav Depends On This
// Josh O'Donnell
// April 2014

#include "Vec3f.h"

Vec3f::Vec3f() {
	this->x = this->y = this->z = 0;
}

Vec3f::Vec3f(const float x, const float y) {
	this->x = x;
	this->y = y;
	this->z = 0;
}

Vec3f::Vec3f(const float x, const float y, const float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vec3f::~Vec3f() {

}

Vec3f Vec3f::Zero() {
	return Vec3f(0, 0, 0);
}

void Vec3f::Normalize() {
	float mag = this->Length();

	this->x /= mag;
	this->y /= mag;
	this->z /= mag;
}

void Vec3f::ComputePolarCoords() {
	this->phi = atan2(this->y, this->x) * 180/PI;
	this->theta = acos(this->z / this->Length()) * 180/PI;
}

void Vec3f::ComputeCartesianCoords() {
	float mag = this->Length();

	this->x = mag * sin(this->phi) * cos(this->theta);
	this->y = mag * sin(this->phi) * sin(this->theta);
	this->z = mag * cos(this->phi);
}

float Vec3f::Length() const {
	return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
}

void Vec3f::SetLength(float length) {
	this->Normalize();

	this->x *= length;
	this->y *= length;
	this->z *= length;
}

void Vec3f::SetValues(const float x, const float y, const float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

float Vec3f::Dot(const Vec3f vec) const {
	return (this->x * vec.x) + (this->y * vec.y) + (this->z * vec.z);
}

Vec3f Vec3f::Lerp(const Vec3f vec, const float interpFactor) const {
	// dest = v1x  + (v2x - v1x) * t	
	float x = this->x + (vec.x - this->x) * interpFactor;
	float y = this->y + (vec.y - this->y) * interpFactor;
	float z = this->z + (vec.z - this->z) * interpFactor;

	return Vec3f(x, y, z);
}

Vec3f Vec3f::Cross(const Vec3f vec) const {
	float x = ((this->y * vec.z) + (this->z * vec.y));
	float y = ((this->x * vec.z) + (this->z * vec.x));
	float z = ((this->x * vec.y) + (this->y * vec.x));

	return Vec3f(x, y, z);
}

Vec3f Vec3f::ProjectionOnto(Vec3f vec) {
	return vec * (this->Dot(vec) / (vec.Length() * vec.Length()));
}

void Vec3f::OrthoNormalize(Vec3f& xVec, Vec3f& yVec, Vec3f& zVec) {
	Vec3f u1 = xVec;
	yVec = yVec - u1 * (yVec.Dot(u1) / (u1.Length() * u1.Length()));
	/* FIX THIS */
	zVec = zVec - (u1 * (zVec.Dot(u1) / (u1.Length() * u1.Length())) - yVec * (zVec - (zVec.Dot(yVec) / (yVec.Length() * yVec.Length()))));
}

std::string Vec3f::ToString() {
	std::stringstream ss(std::stringstream::in | std::stringstream::out);
	std::string toString = "";

	ss << "{x} " << this->x << " {y} " << this->y << " {z} " << this->z << " {length} " << this->Length() << " {theta} " << this->theta << " {phi} " << this->phi;
	toString = ss.str();

	return toString;
}

/****************************/
/***** OPERATOR DEALIES *****/
/****************************/

Vec3f Vec3f::operator+(const Vec3f& vec) {
	float x = this->x + vec.x;
	float y = this->y + vec.y;
	float z = this->z + vec.z;

	return Vec3f(x, y, z);
}

void Vec3f::operator+=(const Vec3f& vec) {
	this->x += vec.x;
	this->y += vec.y;
	this->z += vec.z;
}

Vec3f Vec3f::operator-(const Vec3f& vec) {
	float x = this->x - vec.x;
	float y = this->y - vec.y;
	float z = this->z - vec.z;

	return Vec3f(x, y, z);
}

Vec3f operator-(const Vec3f& lhs, const Vec3f& rhs) {
	float x = lhs.x - rhs.x;
	float y = lhs.y - rhs.y;
	float z = lhs.z - rhs.z;

	return Vec3f(x, y, z);
}

Vec3f Vec3f::operator-(const float scalar) {
	float x = this->x - scalar;
	float y = this->y - scalar;
	float z = this->z - scalar;

	return Vec3f(x, y, z);
}

void Vec3f::operator-=(const Vec3f& vec) {
	this->x -= vec.x;
	this->y -= vec.y;
	this->z -= vec.z;
}

Vec3f Vec3f::operator*(const Vec3f& vec) {
	float x = this->x * vec.x;
	float y = this->y * vec.y;
	float z = this->z * vec.z;

	return Vec3f(x, y, z);
}

Vec3f Vec3f::operator*(const float scalar) {
	float x = this->x * scalar;
	float y = this->y * scalar;
	float z = this->z * scalar;

	return Vec3f(x, y, z);
}

void Vec3f::operator*=(const Vec3f& vec) {
	this->x *= vec.x;
	this->y *= vec.y;
	this->z *= vec.z;
}

void Vec3f::operator*=(const float scalar) {
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
}

Vec3f Vec3f::operator/(const Vec3f& vec) {
	float x = this->x / vec.x;
	float y = this->y / vec.y;
	float z = this->z / vec.z;

	return Vec3f(x, y, z);
}

Vec3f Vec3f::operator/(const float scalar) {
	float x = this->x / scalar;
	float y = this->y / scalar;
	float z = this->z / scalar;
	
	return Vec3f(x, y, z);
}

void Vec3f::operator/=(const Vec3f& vec) {
	this->x /= vec.x;
	this->y /= vec.y;
	this->z /= vec.z;
}

bool Vec3f::operator==(const Vec3f& vec) {
	// Return comparison between angles of vectors tooo
	return ((this->x == vec.x) && (this->y == vec.y) && (this->z == vec.z));
}