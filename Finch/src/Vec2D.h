#pragma once

#include <math.h>
#include <stdlib.h>


struct Vec2D {

public:

	Vec2D() = default;
	Vec2D(const float x, const float y);

	float X() const;
	float Y() const;

	//Operator overloads
	Vec2D operator+(const Vec2D& vec);
	void operator+=(const Vec2D& vec);
	Vec2D operator-(const Vec2D& vec);
	void operator-=(const Vec2D& vec);
	Vec2D operator*(const float n);
	void operator*=(const float n);
	Vec2D operator/(const float n);
	void operator/=(const float n);
	bool operator<(const Vec2D& vec);
	bool operator<=(const Vec2D& vec);
	bool operator>(const Vec2D& vec);
	bool operator>=(const Vec2D& vec);

	Vec2D Copy() const;
	static Vec2D Copy(const Vec2D toCopy);
	static Vec2D Random();
	static Vec2D FromAngle(const float radians);

	void Set(const float x, const float y);
	void SetMag(const float mag);
	static Vec2D SetMag(Vec2D vec, const float mag);
	void Limit(const float magLimit);
	static Vec2D Limit(Vec2D vec, const float magLimit);
	void Normalize();
	static Vec2D Normalize(Vec2D vec);

	float MagSq() const;
	float Mag() const;
	float Heading() const;
	static float AngleBetween(const Vec2D& vec1, const Vec2D& vec2);
	static float Dist(const Vec2D& vec1, const Vec2D& vec2);

	static float Dot(const Vec2D& vec1, const Vec2D& vec2);
	static float Cross(const Vec2D& vec1, const Vec2D& vec2);

private:

	float m_X{ 0.0f };
	float m_Y{ 0.0f };

};