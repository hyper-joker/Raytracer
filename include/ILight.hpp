/*
** EPITECH PROJECT, 2023
** Ilight.hpp
** File description:
** Ilight.hpp
*/
#ifndef RAYTRACER_ILIGHT_HPP
#define RAYTRACER_ILIGHT_HPP

#include "point3D.hpp"
#include "vector3D.hpp"
#include "Ray.hpp"
#include <SFML/Graphics.hpp>

namespace RayTracer {
    class ILight {
        public:
            ILight() = default;
            virtual ~ILight() = default;
            virtual sf::Color AmbientLightCalculate(sf::Color& colorObject) = 0;
            virtual sf::Color applyLight(const Math::Point3D &point, const Math::Point3D &center, sf::Color color) = 0;
    };
}

#endif //RAYTRACER_ILIGHT_HPP
