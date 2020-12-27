#include <iostream>
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

PVec PVec::Copy() {
	PVec vec(x, y, z);
	return vec;
}

PVec PVec::Copy(PVec vec) {
	return vec;
}

float PVec::Mag() { 
	return sqrt(x * x + y * y + z * z);
}

float PVec::MagSq() { 
	return x * x + y * y + z * z; 
}

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

void PVec::Subtract(PVec vec) {
	x -= vec.x;
	y -= vec.y;
	z -= vec.y;
}

void PVec::Subtract(float x_, float y_, float z_) {
	x -= x_;
	y -= y_;
	z -= z_;
}

PVec PVec::Subtract(PVec vec1, PVec vec2) {
	float x_ = vec1.x - vec2.x;
	float y_ = vec1.y - vec2.y;
	float z_ = vec1.z - vec2.z;
	PVec returnVec(x_, y_, z_);
	return returnVec;
}

void PVec::Mult(float n) {
	x *= n;
	y *= n;
	z *= n;
}

PVec PVec::Mult(PVec vec, float n) {
	float x_ = vec.x * n;
	float y_ = vec.y * n;
	float z_ = vec.z * n;
	PVec returnVec(x_, y_, z_);
	return returnVec;
}

void PVec::Div(float n) {
	x /= n;
	y /= n;
	z /= n;
}

PVec PVec::Div(PVec vec, float n) {
	float x_ = vec.x / n;
	float y_ = vec.y / n;
	float z_ = vec.z / n;
	PVec returnVec(x_, y_, z_);
	return returnVec;
}

float PVec::Dist(PVec vec) {
	float xDist = vec.x - x;
	float yDist = vec.y - y;
	float zDist = vec.z - z;
	return sqrt(xDist * xDist + yDist * yDist + zDist * zDist);
}

float PVec::Dist(PVec vec1, PVec vec2) {
	float xDist = vec2.x - vec1.x;
	float yDist = vec2.y - vec1.y;
	float zDist = vec2.z - vec1.z;
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

float PVec::AngleBetween(PVec vec2) {
	PVec vec1(x, y, z);
	float num = PVec::Dot(vec1, vec2);
	float den = vec1.Mag() * vec2.Mag();
	return std::acos(num / den);
}

float PVec::AngleBetween(PVec vec1, PVec vec2) {
	float num = PVec::Dot(vec1, vec2);
	float den = vec1.Mag() * vec2.Mag();
	return std::acos(num / den);
}

void PVec::Normalize() {
	PVec orig(x, y, z);
	float mag = orig.Mag();
	x /= mag;
	y /= mag;
	z /= mag;
}

PVec PVec::Normalize(PVec vec) {
	float mag = vec.Mag();
	float x_ = vec.x / mag;
	float y_ = vec.y / mag;
	float z_ = vec.z / mag;
	PVec returnVector(x_, y_, z_);
	return returnVector;
}

float* PVec::ToArray() {
	float* array = new float[3];
	array[0] = x;
	array[1] = y;
	array[2] = z;
	return array;
}

float* PVec::ToArray(PVec vec) {
	float* array = new float[3];
	array[0] = vec.x;
	array[1] = vec.y;
	array[2] = vec.z;
	return array;
}