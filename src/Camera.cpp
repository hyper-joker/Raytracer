/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
**
*/

#include <iostream>
#include "Camera.hpp"

RayTracer::Camera::Camera(const Math::Point3D &origin, const int &width, const int &height) :
        _origin(origin),
        _screen(Math::Point3D(SCREEN_X, SCREEN_Y, SCREEN_Z), Math::Vector3D(static_cast<double>(width) / 100.0, 0, 0), Math::Vector3D(0, static_cast<double>(height) / 100.0, 0)),
        screenSize(width, height)
{}


RayTracer::Ray RayTracer::Camera::ray(double u, double v)
{
    Math::Point3D p = _screen.pointAt(u, v);
    return {p, Math::Vector3D(p.x - _origin.x, p.y - _origin.y, p.z - _origin.z)};
}