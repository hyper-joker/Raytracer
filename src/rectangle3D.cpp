/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** rectangle3D.cpp
*/

#include <algorithm>
#include <iostream>
#include "rectangle3D.hpp"

RayTracer::Rectangle3D::Rectangle3D(Math::Point3D origin, Math::Vector3D bottom_side, Math::Vector3D left_side) :
        _origin(std::move(origin)),
        _bottom_side(std::move(bottom_side)),
        _left_side(std::move(left_side))
{}

Math::Point3D RayTracer::Rectangle3D::pointAt(double u, double v)
{
    return _origin + _bottom_side * u + _left_side * v;
}
