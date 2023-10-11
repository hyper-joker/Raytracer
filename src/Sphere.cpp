/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
**
*/

#include <algorithm>
#include <iostream>
#include <cmath>
#include "Sphere.hpp"

RayTracer::Sphere::Sphere(Math::Point3D center, double radius, sf::Color color) :
        _color(color),
        _center(std::move(center)),
        _normal({0, 0, 0}),
        _radius(radius)
{}

bool RayTracer::Sphere::hits(const RayTracer::Ray &ray)
{
    Math::Vector3D oc = Math::Vector3D(
            ray._origin.x - _center.x,
            ray._origin.y - _center.y,
            ray._origin.z - _center.z
    );

    double a = ray._distance.dot(ray._distance);
    double b = 2.0 * oc.dot(ray._distance);
    double c = oc.dot(oc) - _radius * _radius;
    double discriminant = (b * b) - (4.0 * a * c);
    return (discriminant >= 0);
}

Math::Point3D RayTracer::Sphere::impact(const RayTracer::Ray &ray)
{
    Math::Vector3D oc = Math::Vector3D(
            ray._origin.x - _center.x,
            ray._origin.y - _center.y,
            ray._origin.z - _center.z);

    double a = ray._distance.dot(ray._distance);
    double b = 2.0 * oc.dot(ray._distance);
    double c = oc.dot(oc) - _radius * _radius;
    double discriminant = (b * b) - (4.0 * a * c);
    Math::Point3D impactPoint = {0, 0, 0};

    if (discriminant >= 0) {
        double t = (-b - sqrt(discriminant)) / (2.0 * a);

        impactPoint.x = ray._origin.x + t * ray._distance.x;
        impactPoint.y = ray._origin.y + t * ray._distance.y;
        impactPoint.z = ray._origin.z + t * ray._distance.z;

    }
    return impactPoint;
}

sf::Color Sphere::getColor() const {
    return _color;
}

Math::Point3D Sphere::getPoint() const
{
    return _center;
}