/*
** EPITECH PROJECT, 2023
** AmbientLighting.cpp
** File description:
** AmbientLighting.cpp
*/

#include "AmbientLighting.hpp"
#include "Sphere.hpp"
#include "iostream"

RayTracer::AmbientLighting::AmbientLighting(const sf::Color &ColorLight, double intensity)
{
    _intensity = intensity;

    _ColorLight.r = ColorLight.r;
    _ColorLight.g = ColorLight.g;
    _ColorLight.b = ColorLight.b;
}

sf::Color RayTracer::AmbientLighting::AmbientLightCalculate(sf::Color& colorObject)
{
    sf::Color _TheColorObject;
    _TheColorObject.r = colorObject.r * _intensity * static_cast<double>(_ColorLight.r);
    _TheColorObject.g = colorObject.g * _intensity * static_cast<double>(_ColorLight.g);
    _TheColorObject.b = colorObject.b * _intensity * static_cast<double>(_ColorLight.b);
    return _TheColorObject;
}

sf::Color RayTracer::AmbientLighting::applyLight(const Math::Point3D &point, const Math::Point3D &center, sf::Color color)
{
    return color;
}