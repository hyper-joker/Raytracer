/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Ilights.hpp
*/

#ifndef RAYTRACER_ILIGHTS_HPP
#define RAYTRACER_ILIGHTS_HPP

#include "point3D.hpp"
#include "vector3D.hpp"
#include "Ray.hpp"
#include <SFML/Graphics.hpp>

namespace RayTracer {
    class ILights {
    public:
        virtual ~ILights() = default;
        virtual sf::Color AmbientLightCalculate(sf::Color& colorObject) = 0;
        virtual sf::Color applyLightToSphere(const Math::Point3D &point, const Math::Point3D &center, sf::Color color) = 0;
        virtual sf::Color applyLightToPlane(const Math::Point3D &point, const Math::Point3D &normal, sf::Color color) = 0;
    };
}

#endif //RAYTRACER_ILIGHTS_HPP
