#include <iostream>
#include <cmath>
#include "PVec.h"

PVec::PVec(float x_, float y_) {
	x = x_;
	y = y_;
}

PVec::PVec(float x_, float y_, float z_) {
	x = x_;
	y = y_;
	z = z_;
}

float PVec::Mag() { return (float)(std::sqrt(x * x + y * y + z * z)); }
float PVec::MagSq() { return x * x + y * y + z * z; }

void PVec::PrintVals() {
	std::cout << "[" << x << ", " << y << ", " << z << "]" << std::endl;
}

void PVec::PrintVals(PVec vec) {
	std::cout << "[" << vec.x << ", " << vec.y << ", " << vec.z << "]" << std::endl;
}

void PVec::Set(float x_, float y_, float z_) {
	x = x_;
	y = y_;
	z = z_;
}

void PVec::Set(float x_, float y_) {
	x = x_;
	y = y_;
}

void PVec::Add(PVec vec) {
	x += vec.x;
	y += vec.y;
	z += vec.y;
}

void PVec::Add(float x_, float y_, float z_) {
	x += x_;
	y += y_;
	z += z_;
}

PVec PVec::Add(PVec vec1, PVec vec2) {
	float x_ = vec1.x + vec2.x;
	float y_ = vec1.y + vec2.y;
	float z_ = vec1.z + vec2.z;
	PVec returnVec(x_, y_, z_);
	return returnVec;
}

PVec PVec::Copy() {
	PVec vec(x, y, z);
	return vec;
}

void PVec::Mult(float n) {
	x *= n;
	y *= n;
	z *= n;
}

void PVec::Div(float n) {
	x /= n;
	y /= n;
	z /= n;
}

float PVec::Dist(PVec vec) {
	float xDist = vec.x - x;
	float yDist = vec.y - y;
	float zDist = vec.z - z;
	return sqrt(xDist * xDist + yDist * yDist + zDist * zDist);
}

float PVec::Dot(PVec vec) {
	float x_ = vec.x * x;
	float y_ = vec.y * y;
	float z_ = vec.z * z;
	return x_ + y_ + z_;
}

float PVec::Dot(PVec vec1, PVec vec2) {
	float x_ = vec1.x * vec2.x;
	float y_ = vec1.y * vec2.y;
	float z_ = vec1.z * vec2.z;
	return x_ + y_ + z_;
}

float PVec::AngleBetween(PVec vec2) {
	PVec vec1(x, y, z);
	float num = vec1.Dot(vec2);
	float den = vec1.Mag() * vec2.Mag();
	return std::acos(num / den);
}

PVec PVec::Cross(PVec vec) {
	float x_ = y * vec.z - z * vec.y;
	float y_ = z * vec.x - x * vec.z;
	float z_ = x * vec.y - y * vec.x;
	PVec returnVector(x_, y_, z_);
	return returnVector;
}

PVec PVec::Cross(PVec vec1, PVec vec2) {
	float x_ = vec1.y * vec2.z - vec1.z * vec2.y;
	float y_ = vec1.z * vec2.x - vec1.x * vec2.z;
	float z_ = vec1.x * vec2.y - vec1.y * vec2.x;
	PVec returnVector(x_, y_, z_);
	return returnVector;
}

void PVec::Normalize() {
	PVec orig(x, y, z);
	float mag = orig.Mag();
	x /= mag;
	y /= mag;
	z /= mag;
}

float* PVec::ToArray() {
	float* array = new float[3];
	array[0] = x;
	array[1] = y;
	array[2] = z;
	return array;
}