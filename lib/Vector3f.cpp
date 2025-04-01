#include "Vector3f.h"

Vector3f::Vector3f()
    : x(0.f), y(0.f), z(0.f)
{
}

Vector3f::Vector3f(float x, float y, float z)
    : x(x), y(y), z(z)
{
}

bool Vector3f::operator==(const Vector3f &rhs) const
{
    return x == rhs.x && y == rhs.y && z == rhs.z;
}

bool Vector3f::operator!=(const Vector3f &rhs) const
{
    return !(*this == rhs);
}
