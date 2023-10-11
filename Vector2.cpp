#include "Vector2.h"
#include <cmath>

//initilize static member
const Vector2 Vector2::Zero = Vector2(0, 0);
const Vector2 Vector2::One = Vector2(1, 1);
const Vector2 Vector2::UnitX = Vector2(1, 0);
const Vector2 Vector2::UnitY = Vector2(0, 1);


Vector2::Vector2(float _x, float _y)
{
	m_x = _x;
	m_y = _y;
}

float Vector2::Length() const
{
	return std::sqrtf(m_x * m_x + m_y * m_y);
}

float Vector2::LengthSquared() const
{
	return (m_x * m_x + m_y * m_y);
}

float Vector2::Dot(const Vector2& v) const
{
	return (m_x * v.m_x + m_y * v.m_y);
}

void Vector2::Normalize()
{
	float len = Length();
	if (len == 0.0f)
	{
		return;
	}
	len = 1.0f / len;
	m_x *= len;
	m_y *= len;
}

Vector2 Vector2::Lerp(Vector2& start, Vector2& end, float t)
{
	return Vector2(std::lerp(start.m_x, end.m_x, t),
				   std::lerp(start.m_y, end.m_y, t));
}