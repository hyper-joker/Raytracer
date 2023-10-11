/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Plane.cpp
*/

#include <iostream>
#include <utility>
#include "Plane.hpp"

RayTracer::Plane::Plane(std::string axis, int pos, sf::Color color) :
        _normal({0, 1, 0}),
        _color(color),
        _axis(std::move(axis))
{
    if (_axis == "X") {
        _point.x = pos;
    } else if (_axis == "Y") {
        _point.y = pos;
    } else if (_axis == "Z") {
        _point.z = pos;
    }
}

bool RayTracer::Plane::hits(const RayTracer::Ray& ray)
{
    double dotProduct = ray._distance.dot(_normal) * (-1);

    if (std::abs(dotProduct) < 0.0) {
        return false;
    }
    Math::Vector3D originToPlane = {
            _point.x - ray._origin.x,
            _point.y - ray._origin.y,
            _point.z - ray._origin.z
    };
    double t = originToPlane.dot(_normal) / dotProduct;
    if (t < 0) {
        return false;
    }
    return true;
}

Math::Point3D RayTracer::Plane::impact(const RayTracer::Ray& ray)
{
    double dotProduct = ray._distance.dot(_normal) * (-1);

    if (std::abs(dotProduct) < 0.0) {
        return {0, 0, 0};
    }
    Math::Vector3D originToPlane = {
            _point.x - ray._origin.x,
            _point.y - ray._origin.y,
            _point.z - ray._origin.z
    };
    double t = originToPlane.dot(_normal) / dotProduct;
    if (t < 0) {
        return {0, 0, 0};
    }
    Math::Point3D impactPoint = {
            ray._origin.x + t * ray._distance.x,
            ray._origin.y + t * ray._distance.y,
            ray._origin.z + t * ray._distance.z
    };
    return impactPoint;
}

sf::Color Plane::getColor() const {
    return _color;
}

Math::Point3D Plane::getPoint() const {
    return _point;
}
