#include "Vec2D.h"

Vec2D::Vec2D(const float x, const float y) : m_X{ x }, m_Y{ y }
{
}

float Vec2D::X() const
{
	return m_X;
}

float Vec2D::Y() const
{
	return m_Y;
}

Vec2D Vec2D::Copy() const
{
	return { m_X, m_Y };
}

Vec2D Vec2D::Copy(const Vec2D toCopy)
{
	return { toCopy.m_X, toCopy.m_Y };
}

Vec2D Vec2D::Random()
{
	return { Normalize({ static_cast<float>(rand() % 100), static_cast<float>(rand() % 100) }) };
}

Vec2D Vec2D::FromAngle(const float radians)
{
	return { static_cast<float>(cos(radians)), static_cast<float>(sin(radians)) };
}

void Vec2D::Set(const float x, const float y)
{
	m_X = { x };
	m_Y = { y };
}

void Vec2D::SetMag(const float mag)
{
	Normalize();
	*this *= mag;
}

Vec2D Vec2D::SetMag(Vec2D vec, const float mag)
{
	vec.Normalize();
	return vec * mag;
}

void Vec2D::Limit(const float magLimit)
{
	if (MagSq() > (magLimit * magLimit))
	{
		SetMag(magLimit);
	}
}

Vec2D Vec2D::Limit(Vec2D vec, const float magLimit)
{
	if (vec.MagSq() > magLimit * magLimit)
	{
		return SetMag(vec, magLimit);
	}
}

void Vec2D::Normalize()
{
	*this /= Mag();
}

Vec2D Vec2D::Normalize(Vec2D vec)
{
	return vec / vec.Mag();
}

float Vec2D::MagSq() const
{
	return m_X * m_X + m_Y * m_Y;
}

float Vec2D::Mag() const
{
	return static_cast<float>(sqrt(MagSq()));
}

float Vec2D::Heading() const
{
	return static_cast<float>(atan2(m_Y, m_X));
}

float Vec2D::AngleBetween(const Vec2D& vec1, const Vec2D& vec2)
{
	return acos( Dot(vec1, vec2) / (vec1.Mag() * vec2.Mag()) );
}

float Vec2D::Dist(const Vec2D& vec1, const Vec2D& vec2)
{
	const float distX{ vec2.m_X - vec1.m_X };
	const float distY{ vec2.m_Y - vec2.m_Y };
	return sqrt(distX * distX + distY * distY);
}

float Vec2D::Dot(const Vec2D& vec1, const Vec2D& vec2)
{
	return (vec1.m_X * vec2.m_X + vec1.m_Y * vec2.m_Y);
}

float Vec2D::Cross(const Vec2D& vec1, const Vec2D& vec2)
{
	return (vec1.m_X * vec2.m_Y, - vec1.m_Y * vec2.m_X );
}

Vec2D Vec2D::operator+(const Vec2D& vec)
{
	return { m_X + vec.m_X, m_Y + vec.m_Y };
}

void Vec2D::operator+=(const Vec2D& vec)
{
	m_X += vec.m_X;
	m_Y += vec.m_Y;
}

Vec2D Vec2D::operator-(const Vec2D& vec)
{
	return { m_X - vec.m_X, m_Y - vec.m_Y };
}

void Vec2D::operator-=(const Vec2D& vec)
{
	m_X -= vec.m_X;
	m_Y -= vec.m_Y;
}

Vec2D Vec2D::operator*(const float n)
{
	return { m_X * n, m_Y * n };
}

void Vec2D::operator*=(const float n)
{
	m_X *= n;
	m_Y *= n;
}

Vec2D Vec2D::operator/(const float n)
{
	return { m_X / n, m_Y / n };
}

void Vec2D::operator/=(const float n)
{
	m_X /= n;
	m_Y /= n;
}

bool Vec2D::operator<(const Vec2D& vec)
{
	return MagSq() < vec.MagSq();
}

bool Vec2D::operator<=(const Vec2D& vec)
{
	return MagSq() <= vec.MagSq();
}

bool Vec2D::operator>(const Vec2D& vec)
{
	return MagSq() > vec.MagSq();
}

bool Vec2D::operator>=(const Vec2D& vec)
{
	return MagSq() >= vec.MagSq();
}