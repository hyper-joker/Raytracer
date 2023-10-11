/*
** EPITECH PROJECT, 2023
** AmbientLighting.h
** File description:
** AmbientLighting.h
*/
#ifndef RAYTRACER_LIGHTING_H
#define RAYTRACER_LIGHTING_H

#include <vector3D.hpp>
#include <string>
#include "ILight.hpp"
#include <Ray.hpp>
#include <Sphere.hpp>
#include <SFML/Graphics.hpp>

namespace RayTracer {
    class AmbientLighting : public ILight {
        public:
        AmbientLighting(const sf::Color& ColorLight, double intensity);

        sf::Color AmbientLightCalculate(sf::Color& colorObject) override;
        sf::Color applyLight(const Math::Point3D &point, const Math::Point3D &center, sf::Color color) override;

        sf::Color _ColorLight;
        double _intensity;
    };
}

#endif //RAYTRACER_LIGHTING_H
