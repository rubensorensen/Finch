#include <iostream>
#include <cmath>
#include <cstdlib>
#include "PVec.h"

PVec::PVec() = default;

PVec::PVec(const float x, const float y) {
	this->x = x;
	this->y = y;
}

PVec::PVec(const float x, const float y, const float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

PVec PVec::Copy() const {
	return *this;
}

PVec PVec::Copy(const PVec vec) {
	return vec;
}

float PVec::Mag() const { 
	return std::sqrt(  
			  this->x * this->x 
			+ this->y * this->y
			+ this->z * this->z  );
}

float PVec::MagSq() const { 
	return	  this->x * this->x 
			+ this->y * this->y 
			+ this->z * this->z;
}

void PVec::PrintVals() const {
	std::cout	<< "[" << this->x 
				<< ", " << this->y 
				<< ", " << this->z 
				<< "]" << std::endl;
}

void PVec::PrintVals(const PVec vec) {
	std::cout	<< "[" << vec.x 
				<< ", " << vec.y 
				<< ", " << vec.z 
				<< "]" << std::endl;
}

void PVec::Set(const float x, const float y, const float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void PVec::Set(const float x, const float y) {
	this->x = x;
	this->y = y;
}

PVec PVec::Random2D() {
	const auto x = static_cast<float>(rand() % 100);
	const auto y = static_cast<float>(rand() % 100);
	return PVec::Normalize(PVec(x, y, 0));
}

PVec PVec::Random3D() {
	const auto x = static_cast<float>(rand() % 100);
	const auto y = static_cast<float>(rand() % 100);
	const auto z = static_cast<float>(rand() % 100);
	return PVec::Normalize(PVec(x, y, z));
}

void PVec::Add(const PVec vec) {
	this->x += vec.x;
	this->y += vec.y;
	this->z += vec.y;
}

void PVec::Add(const float x, const float y, const float z) {
	this->x += x;
	this->y += y;
	this->z += z;
}

PVec PVec::Add(const PVec vec1, const PVec vec2) {
	const float x = vec1.x + vec2.x;
	const float y = vec1.y + vec2.y;
	const float z = vec1.z + vec2.z;
	return { x, y, z };
}

void PVec::Sub(const PVec vec) {
	this->x -= vec.x;
	this->y -= vec.y;
	this->z -= vec.y;
}

void PVec::Sub(const float x, const float y, const float z) {
	this->x -= x;
	this->y -= y;
	this->z -= z;
}

PVec PVec::Sub(const PVec vec1, const PVec vec2) {
	const float x = vec1.x - vec2.x;
	const float y = vec1.y - vec2.y;
	const float z = vec1.z - vec2.z;
	return { x, y, z };
}

void PVec::Mult(float n) {
	this->x *= n;
	this->y *= n;
	this->z *= n;
}

PVec PVec::Mult(const PVec vec, const float n) {
	const float x = vec.x * n;
	const float y = vec.y * n;
	const float z = vec.z * n;
	return { x, y, z };
}

void PVec::Div(const float n) {
	const float factor = 1 / n;
	this->x *= factor;
	this->y *= factor;
	this->z *= factor;
}

PVec PVec::Div(const PVec vec, const float n) {
	const float factor = 1 / n;
	const float x = vec.x * factor;
	const float y = vec.y * factor;
	const float z = vec.z * factor;
	return { x, y, z };
}

float PVec::Dist(const PVec vec) const {
	const float xDist = vec.x - this->x;
	const float yDist = vec.y - this->y;
	const float zDist = vec.z - this->z;
	return std::sqrt(xDist * xDist + yDist * yDist + zDist * zDist);
}

float PVec::Dist(const PVec vec1, const PVec vec2) {
	const float xDist = vec2.x - vec1.x;
	const float yDist = vec2.y - vec1.y;
	const float zDist = vec2.z - vec1.z;
	return std::sqrt(xDist * xDist + yDist * yDist + zDist * zDist);
}

float PVec::Dot(const PVec vec) const {
	const float x = vec.x * this->x;
	const float y = vec.y * this->y;
	const float z = vec.z * this->z;
	return x + y + z;
}

float PVec::Dot(const PVec vec1, const PVec vec2) {
	const float x = vec1.x * vec2.x;
	const float y = vec1.y * vec2.y;
	const float z = vec1.z * vec2.z;
	return x + y + z;
}

PVec PVec::Cross(const PVec vec) const {
	const float x = this->y * vec.z - this->z * vec.y;
	const float y = this->z * vec.x - this->x * vec.z;
	const float z = this->x * vec.y - this->y * vec.x;
	return { x, y, z };
}

PVec PVec::Cross(const PVec vec1, const PVec vec2) {
	const float x = vec1.y * vec2.z - vec1.z * vec2.y;
	const float y = vec1.z * vec2.x - vec1.x * vec2.z;
	const float z = vec1.x * vec2.y - vec1.y * vec2.x;
	return { x, y, z };
}

float PVec::AngleBetween(const PVec vec) const {
	const float num = Dot(*this, vec);
	const float den = this->Mag() * vec.Mag();
	return std::acos(num / den);
}

float PVec::AngleBetween(const PVec vec1, const PVec vec2) {
	const float num = Dot(vec1, vec2);
	const float den = vec1.Mag() * vec2.Mag();
	return std::acos(num / den);
}

void PVec::Normalize() {
	const float mag = this->Mag();
	return this->Div(mag);
}

PVec PVec::Normalize(PVec vec) {
	const float mag = vec.Mag();
	vec.Div(mag);
	return vec;
}

void PVec::SetMag(const float mag) {
	this->Normalize();
	this->Mult(mag);
}

PVec PVec::SetMag(PVec vec, const float mag) {
	vec.Normalize();
	vec.Mult(mag);
	return vec;
}

void PVec::Limit(const float magLimit) {
	if (this->MagSq() > magLimit * magLimit) {
		this->SetMag(magLimit);
	}
}

PVec PVec::Limit(PVec vec, const float magLimit) {
	if (vec.MagSq() > magLimit * magLimit) {
		return SetMag(vec, magLimit);
    }
	return vec;
}

float* PVec::ToArray() const {
	return new float[3]{ x, y, z };
}

float* PVec::ToArray(const PVec vec) {
	return new float[3]{ vec.x, vec.y, vec.z };
}