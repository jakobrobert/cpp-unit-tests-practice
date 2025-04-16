#include "Vector3.h"

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
