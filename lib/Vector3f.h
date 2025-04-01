class Vector3f
{
public:
    Vector3f();
    Vector3f(float x, float y, float z);

    bool operator==(const Vector3f& rhs) const;
    bool Vector3f::operator!=(const Vector3f &rhs) const;

public:
    float x;
    float y;
    float z;
};
