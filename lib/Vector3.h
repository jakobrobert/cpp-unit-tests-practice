class Vector3 // MYTODO rename to Vector3, including file names
{
public:
    Vector3();
    Vector3(float x, float y, float z);

    bool operator==(const Vector3& rhs) const;
    bool Vector3::operator!=(const Vector3 &rhs) const;

    Vector3& operator+=(const Vector3& rhs);
    Vector3 operator+(const Vector3& rhs) const;
    Vector3& operator-=(const Vector3& rhs);
    Vector3 operator-(const Vector3& rhs) const;

    // MYTODO Normalize
    // MYTODO LengthSquared, Length

    // MYTODO Dot product
    // MYTODO Cross product

public:
    float x;
    float y;
    float z;
};
