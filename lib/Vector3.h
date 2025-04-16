class Vector3
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

    float DotProduct(const Vector3& rhs) const;
    Vector3 CrossProduct(const Vector3& rhs) const;

    // TODO Normalize
    // TODO LengthSquared, Length

public:
    float x;
    float y;
    float z;
};
