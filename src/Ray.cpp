/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
**
*/

#include <algorithm>

#include "Ray.hpp"

RayTracer::Ray::Ray() :
        _origin(Math::Point3D()),
        _distance(Math::Vector3D())
{}

RayTracer::Ray::Ray(Math::Point3D origin, Math::Vector3D distance) :
        _origin(std::move(origin)),
        _distance(std::move(distance))
{}

RayTracer::Ray::Ray(const Ray &other) :
        _origin(other._origin),
        _distance(other._distance)
{}

RayTracer::Ray::Ray(Ray &&other) noexcept :
        _origin(other._origin),
        _distance(other._distance)
{
    if (this != &other) {
        _origin = other._origin;
        _distance = other._distance;

        other._origin = Math::Point3D();
        other._distance = Math::Vector3D();
    }
}

RayTracer::Ray &RayTracer::Ray::operator=(const RayTracer::Ray &other)
{
    if (this != &other) {
        _origin = other._origin;
        _distance = other._distance;
    }
    return *this;
}

RayTracer::Ray &RayTracer::Ray::operator=(RayTracer::Ray &&other) noexcept
{
    if (this != &other) {
        _origin = other._origin;
        _distance = other._distance;

        other._origin = Math::Point3D();
        other._distance = Math::Vector3D();
    }
    return *this;
}
