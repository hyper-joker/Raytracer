/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
**
*/

#ifndef RAYTRACER_SPHERE_HPP
#define RAYTRACER_SPHERE_HPP

#include <SFML/Graphics.hpp>

#include "point3D.hpp"
#include "Ray.hpp"
#include "IPrimitives.hpp"

namespace RayTracer {

class Sphere : public IPrimitives {
public:
    Sphere(Math::Point3D center, double radius, sf::Color color);
    ~Sphere() override = default;

    bool hits(const Ray &ray) override;
    Math::Point3D impact(const Ray &ray) override;
    sf::Color getColor() const override;
    Math::Point3D getPoint() const override;

    sf::Color _color;
    Math::Point3D _center;
    Math::Vector3D _normal;
    double _radius;
};

}

#endif //RAYTRACER_SPHERE_HPP
