/*
** EPITECH PROJECT, 2023
** point3D.cpp
** File description:
** point3D.cpp
*/

#include "point3D.hpp"

Math::Point3D::Point3D() :
    x(0),
    y(0),
    z(0)
{}

Math::Point3D::Point3D(double x, double y, double z) :
    x(x),
    y(y),
    z(z)
{}

Math::Point3D::Point3D(const Point3D& other) :
    x(other.x),
    y(other.y),
    z(other.z)
{}

Math::Point3D::Point3D(Point3D&& other) noexcept :
    x(other.x),
    y(other.y),
    z(other.z)
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

Math::Point3D &Math::Point3D::operator=(const Point3D& other)
{
    if (this != &other) {
        x = other.x;
        y = other.y;
        z = other.z;
    }
    return *this;
}

Math::Point3D& Math::Point3D::operator=(Point3D&& other) noexcept
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

Math::Point3D Math::Point3D::operator+(const Math::Vector3D& other) const
{
    return {x + other.x, y + other.y, z + other.z};
}

Math::Point3D& Math::Point3D::operator+=(Math::Vector3D& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Math::Point3D Math::Point3D::operator-(const Math::Point3D &point) const
{
    return {x - point.x, y - point.y, z - point.z};
}
