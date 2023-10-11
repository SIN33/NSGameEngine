#pragma once

struct Vector2
{
	float m_x = 0.0f;
	float m_y = 0.0f;

	Vector2() = default;
	Vector2(float x, float y);

	// Constants
	static const Vector2 Zero;
	static const Vector2 One;
	static const Vector2 UnitX;
	static const Vector2 UnitY;

	float Length() const;
	float LengthSquared() const;

	float Dot(const Vector2& v) const;

	void Normalize();

	// interpolate
	static Vector2 Lerp(Vector2& _start, Vector2& _end, float _t);

	// overload operator
	bool operator==(const Vector2& _v) const;
	bool operator!=(const Vector2& _v) const;

	Vector2& operator+=(const Vector2& _v);
	Vector2	 operator+(const Vector2& _v) const;

	Vector2& operator-=(const Vector2& _v);
	Vector2	 operator-(const Vector2& _v) const;

	Vector2& operator*=(const Vector2& _v);
	Vector2	 operator*(const Vector2& _v) const;
	Vector2& operator*=(float _val);
	Vector2	 operator*(float _val) const;

	Vector2& operator/=(const Vector2& _v);
	Vector2	 operator/(const Vector2& _v) const;
	Vector2& operator/=(float _val);
	Vector2	 operator/(float _val) const;
};

inline Vector2::Vector2(float x, float y)
{
}

inline bool Vector2::operator==(const Vector2& _v) const
{
	return (m_x == _v.m_x && m_y == _v.m_y);
}

inline bool Vector2::operator!=(const Vector2& _v) const
{
	return (m_x != _v.m_x || m_y != _v.m_y);
}

inline Vector2& Vector2::operator+=(const Vector2& _v)
{
	m_x += _v.m_x;
	m_y += _v.m_y;
	return (*this);
}

inline Vector2 Vector2::operator+(const Vector2& _v) const
{
	return Vector2(m_x + _v.m_x, m_y + _v.m_y);
}

inline Vector2& Vector2::operator-=(const Vector2& _v)
{
	m_x -= _v.m_x;
	m_y -= _v.m_y;
	return (*this);
}

inline Vector2 Vector2::operator-(const Vector2& _v) const
{
	return Vector2(m_x - _v.m_x, m_y - _v.m_y);
}

inline Vector2& Vector2::operator*=(const Vector2& _v)
{
	m_x *= _v.m_x;
	m_y *= _v.m_y;
	return (*this);
}

inline Vector2 Vector2::operator*(const Vector2& _v) const
{
	return Vector2(m_x * _v.m_x, m_y * _v.m_y);
}

inline Vector2& Vector2::operator*=(float _val)
{
	m_x *= _val;
	m_y *= _val;
	return (*this);
}

inline Vector2 Vector2::operator*(float _val) const
{
	return Vector2(m_x + _val, m_y + _val);
}

inline Vector2& Vector2::operator/=(const Vector2& _v)
{
	m_x /= _v.m_x;
	m_y /= _v.m_y;
	return (*this);
}

inline Vector2 Vector2::operator/(const Vector2& _v) const
{
	return Vector2(m_x / _v.m_x, m_y / _v.m_y);
}

inline Vector2& Vector2::operator/=(float _val)
{
	m_x /= _val;
	m_y /= _val;
	return (*this);
}

inline Vector2 Vector2::operator/(float _val) const
{
	return Vector2(m_x / _val, m_y / _val);
}

