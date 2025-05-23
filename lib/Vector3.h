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

    Vector3& operator*=(float rhs);
    Vector3 operator*(float rhs) const;
    Vector3& operator/=(float rhs);
    Vector3 operator/(float rhs) const;

    float DotProduct(const Vector3& rhs) const;
    Vector3 CrossProduct(const Vector3& rhs) const;

    float LengthSquared() const;
    float Length() const;

    Vector3& Normalize();
    Vector3 Normalized() const;

public:
    float x;
    float y;
    float z;
};
