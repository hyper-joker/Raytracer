/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Plane.hpp
*/

#ifndef PLANE_HPP_
	#define PLANE_HPP_

    #include <SFML/Graphics.hpp>
    #include "Ray.hpp"

#include "IPrimitives.hpp"

namespace RayTracer {
    class Plane : public IPrimitives {
        public:
            Plane(std::string axis, int pos, sf::Color color);
            ~Plane() override = default;

            bool hits(const Ray &ray) override;
            Math::Point3D impact(const Ray &ray) override;
            [[nodiscard]] sf::Color getColor() const override;
            Math::Point3D getPoint() const override;

            Math::Vector3D _normal;
            Math::Point3D _point;
            sf::Color _color;
            std::string _axis;
    };
}

#endif /*PLANE_HPP_*/
