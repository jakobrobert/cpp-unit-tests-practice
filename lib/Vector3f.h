class Vector3f // MYTODO rename to Vector3, including file names
{
public:
    Vector3f();
    Vector3f(float x, float y, float z);

    bool operator==(const Vector3f& rhs) const;
    bool Vector3f::operator!=(const Vector3f &rhs) const;

    Vector3f operator+=(const Vector3f& rhs) const;
    // MYTODO operator+, it calls +=
    // MYTODO operator-=
    // MYTODO operator-, it calls -=

    // MYTODO Normalize
    // MYTODO LengthSquared, Length

    // MYTODO Dot product
    // MYTODO Cross product

public:
    float x;
    float y;
    float z;
};
