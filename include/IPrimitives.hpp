/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** prim
*/

#ifndef RAYTRACER_IPRIMITIVES_HPP
#define RAYTRACER_IPRIMITIVES_HPP

#include <SFML/Graphics.hpp>
#include "Ray.hpp"

using namespace RayTracer;

class IPrimitives {
public:
    virtual ~IPrimitives() = default;
    virtual bool hits(const Ray &ray) = 0;
    virtual Math::Point3D impact(const Ray &ray) = 0;
    virtual sf::Color getColor() const = 0;
    virtual Math::Point3D getPoint() const = 0;

};

#endif //RAYTRACER_IPRIMITIVES_HPP
