#include "Vector3.h"

#include <cmath>
#include <stdexcept>

Vector3::Vector3()
    : x(0.f), y(0.f), z(0.f)
{
}

Vector3::Vector3(float x, float y, float z)
    : x(x), y(y), z(z)
{
}

bool Vector3::operator==(const Vector3 &rhs) const
{
    return x == rhs.x && y == rhs.y && z == rhs.z;
}

bool Vector3::operator!=(const Vector3 &rhs) const
{
    return !(*this == rhs);
}

Vector3& Vector3::operator+=(const Vector3 &rhs)
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}

Vector3 Vector3::operator+(const Vector3& rhs) const
{
    Vector3 result = *this;
    result += rhs;
    return result;
}

Vector3& Vector3::operator-=(const Vector3& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
}

Vector3 Vector3::operator-(const Vector3& rhs) const
{
    Vector3 result = *this;
    result -= rhs;
    return result;
}

Vector3& Vector3::operator*=(float rhs)
{
    x *= rhs;
    y *= rhs;
    z *= rhs;
    return *this;
}

Vector3 Vector3::operator*(float rhs) const
{
    Vector3 result = *this;
    result *= rhs;
    return result;
}

Vector3& Vector3::operator/=(float rhs)
{
    if (rhs == 0.f)
        throw std::domain_error("Cannot divide by zero");

    const float reciprocal = 1.f / rhs;
    *this *= reciprocal;
    return *this;
}

Vector3 Vector3::operator/(float rhs) const
{
    Vector3 result = *this;
    result /= rhs;
    return result;
}

float Vector3::DotProduct(const Vector3& rhs) const
{
    return x * rhs.x + y * rhs.y + z * rhs.z;
}

Vector3 Vector3::CrossProduct(const Vector3 & rhs) const
{
    float resultX = y * rhs.z - z * rhs.y;
    float resultY = z * rhs.x - x * rhs.z;
    float resultZ = x * rhs.y - y * rhs.x;
    return Vector3(resultX, resultY, resultZ);
}

float Vector3::LengthSquared() const
{
    return this->DotProduct(*this);
}

float Vector3::Length() const
{
    return std::sqrtf(LengthSquared());
}

Vector3& Vector3::Normalize()
{
    return *this;
}
