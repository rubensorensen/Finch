#include <iostream>
#include "PVec.h"

PVec::PVec() { }

PVec::PVec(float x, float y) {
	this->x = x;
	this->y = y;
}

PVec::PVec(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

PVec PVec::Copy() {
	return *this;
}

PVec PVec::Copy(PVec vec) {
	return vec;
}

float PVec::Mag() { 
	return sqrt(  this->x * this->x 
				+ this->y * this->y
				+ this->z * this->z  );
		}

float PVec::MagSq() { 
	return	  this->x * this->x 
			+ this->y * this->y 
			+ this->z * this->z;
}

void PVec::PrintVals() {
	std::cout	<< "[" << this->x 
				<< ", " << this->y 
				<< ", " << this->z 
				<< "]" << std::endl;
}

void PVec::PrintVals(PVec vec) {
	std::cout	<< "[" << vec.x 
				<< ", " << vec.y 
				<< ", " << vec.z 
				<< "]" << std::endl;
}

void PVec::Set(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void PVec::Set(float x, float y) {
	this->x = x;
	this->y = y;
}

void PVec::Add(PVec vec) {
	this->x += vec.x;
	this->y += vec.y;
	this->z += vec.y;
}

void PVec::Add(float x, float y, float z) {
	this->x += x;
	this->y += y;
	this->z += z;
}

PVec PVec::Add(PVec vec1, PVec vec2) {
	float x = vec1.x + vec2.x;
	float y = vec1.y + vec2.y;
	float z = vec1.z + vec2.z;
	return PVec(x, y, z);
}

void PVec::Subtract(PVec vec) {
	this->x -= vec.x;
	this->y -= vec.y;
	this->z -= vec.y;
}

void PVec::Subtract(float x, float y, float z) {
	this->x -= x;
	this->y -= y;
	this->z -= z;
}

PVec PVec::Subtract(PVec vec1, PVec vec2) {
	float x = vec1.x - vec2.x;
	float y = vec1.y - vec2.y;
	float z = vec1.z - vec2.z;
	return PVec(x, y, z);
}

void PVec::Mult(float n) {
	this->x *= n;
	this->y *= n;
	this->z *= n;
}

PVec PVec::Mult(PVec vec, float n) {
	float x = vec.x * n;
	float y = vec.y * n;
	float z = vec.z * n;
	return PVec(x, y, z);
}

void PVec::Div(float n) {
	float factor = 1 / n;
	this->x *= factor;
	this->y *= factor;
	this->z *= factor;
}

PVec PVec::Div(PVec vec, float n) {
	float factor = 1 / n;
	float x = vec.x * factor;
	float y = vec.y * factor;
	float z = vec.z * factor;
	return PVec(x, y, z);
}

float PVec::Dist(PVec vec) {
	float xDist = vec.x - this->x;
	float yDist = vec.y - this->y;
	float zDist = vec.z - this->z;
	return sqrt(xDist * xDist + yDist * yDist + zDist * zDist);
}

float PVec::Dist(PVec vec1, PVec vec2) {
	float xDist = vec2.x - vec1.x;
	float yDist = vec2.y - vec1.y;
	float zDist = vec2.z - vec1.z;
	return sqrt(xDist * xDist + yDist * yDist + zDist * zDist);
}

float PVec::Dot(PVec vec) {
	float x = vec.x * this->x;
	float y = vec.y * this->y;
	float z = vec.z * this->z;
	return x + y + z;
}

float PVec::Dot(PVec vec1, PVec vec2) {
	float x = vec1.x * vec2.x;
	float y = vec1.y * vec2.y;
	float z = vec1.z * vec2.z;
	return x + y + z;
}

PVec PVec::Cross(PVec vec) {
	float x = this->y * vec.z - this->z * vec.y;
	float y = this->z * vec.x - this->x * vec.z;
	float z = this->x * vec.y - this->y * vec.x;
	return PVec(x, y, z);
}

PVec PVec::Cross(PVec vec1, PVec vec2) {
	float x = vec1.y * vec2.z - vec1.z * vec2.y;
	float y = vec1.z * vec2.x - vec1.x * vec2.z;
	float z = vec1.x * vec2.y - vec1.y * vec2.x;
	return PVec(x, y, z);
}

float PVec::AngleBetween(PVec vec) {
	float num = PVec::Dot(*this, vec);
	float den = this->Mag() * vec.Mag();
	return std::acos(num / den);
}

float PVec::AngleBetween(PVec vec1, PVec vec2) {
	float num = PVec::Dot(vec1, vec2);
	float den = vec1.Mag() * vec2.Mag();
	return std::acos(num / den);
}

void PVec::Normalize() {
	float mag = this->Mag();
	return this->Div(mag);
}

PVec PVec::Normalize(PVec vec) {
	float mag = vec.Mag();
	vec.Div(mag);
	return vec;
}

void PVec::SetMag(float mag) {
	this->Normalize();
	this->Mult(mag);
}

PVec PVec::SetMag(PVec vec, float mag) {
	vec.Normalize();
	vec.Mult(mag);
	return vec;
}

void PVec::Limit(float magLimit) {
	if (this->MagSq() > magLimit * magLimit) {
		this->SetMag(magLimit);
	}
}

PVec PVec::Limit(PVec vec, float magLimit) {
	if (vec.MagSq() > magLimit * magLimit) {
		return SetMag(vec, magLimit);
    }
	return vec;
}

float* PVec::ToArray() {
	return new float[3]{ x, y, z };
}

float* PVec::ToArray(PVec vec) {
	return new float[3]{ vec.x, vec.y, vec.z };
}