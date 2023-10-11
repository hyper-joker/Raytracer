/*
** EPITECH PROJECT, 2023
** bs_raytracer
** File description:
**
*/

#include <cmath>

#include "vector3D.hpp"

Math::Vector3D::Vector3D() : x(0), y(0), z(0)
{
}

Math::Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z)
{

}

Math::Vector3D::Vector3D(const Vector3D& other) : x(other.x), y(other.y), z(other.z)
{

}

Math::Vector3D::Vector3D(Vector3D&& other) : x(other.x), y(other.y), z(other.z)
{
    if (this != &other) {
        x = other.x;
        y = other.y;
        z = other.z;
        other.x = 0;
        other.y = 0;
        other.z = 0;
    }
}

Math::Vector3D &Math::Vector3D::operator=(const Vector3D& other)
{
    if (this != &other) {
        x = other.x;
        y = other.y;
        z = other.z;
    }
    return *this;
}

Math::Vector3D &Math::Vector3D::operator=(Vector3D&& other)
{
    if (this != &other) {
        x = other.x;
        y = other.y;
        z = other.z;
        other.x = 0;
        other.y = 0;
        other.z = 0;
    }
    return *this;
}

double Math::Vector3D::length() const
{
    return sqrt((x * x) + (y * y) + (z * z));
}

double Math::Vector3D::dot(const Vector3D& other) const
{
    return ((x * other.x) + (y * other.y) + (z * other.z));
}

Math::Vector3D Math::Vector3D::operator+(const Vector3D& other) const
{
    return Vector3D(x + other.x, y + other.y, z + other.z);
}

Math::Vector3D& Math::Vector3D::operator+=(const Math::Vector3D &other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Math::Vector3D Math::Vector3D::operator-(const Math::Vector3D &other) const
{
    return Vector3D(x - other.x, y - other.y, z - other.z);
}

Math::Vector3D& Math::Vector3D::operator-=(const Vector3D& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Math::Vector3D Math::Vector3D::operator*(double scalar) const
{
    return Vector3D(x*scalar, y*scalar, z*scalar);
}

Math::Vector3D& Math::Vector3D::operator*=(double scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

Math::Vector3D Math::Vector3D::operator/(double scalar) const
{
    return Vector3D(x/scalar, y/scalar, z/scalar);
}

Math::Vector3D& Math::Vector3D::operator/=(double scalar)
{
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}
