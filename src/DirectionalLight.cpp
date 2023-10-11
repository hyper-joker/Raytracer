/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** DirectionalLight.cpp
*/

#include <cmath>
#include <utility>
#include <iostream>
#include "DirectionalLight.hpp"

RayTracer::DirectionalLight::DirectionalLight(double degree, double intensity, double z, sf::Color color) :
    _degree(degree),
    _direction({cos((degree) * M_PI / 180), sin((degree) * M_PI / 180), z}),
    _color(color),
    _intensity(intensity)
{}

sf::Color RayTracer::DirectionalLight::applyLight(const Math::Point3D& point, const Math::Point3D& center, sf::Color color)
{
    Math::Vector3D impactNormal = {
            point.x - center.x,
            point.y - center.y,
            point.z - center.z
    };
    double dotProduct = impactNormal.dot(_direction);
    double r = color.r * (dotProduct * (-1));
    double g = color.g * (dotProduct * (-1));
    double b = color.b * (dotProduct * (-1));

    r *= _intensity * (_color.r / 255.0);
    if (r < 0)
        r = 0;
    else if (r > 255)
        r = 255;

    g *= _intensity * (_color.g / 255.0);
    if (g < 0)
        g = 0;
    else if (g > 255)
        g = 255;

    b *= _intensity * (_color.b / 255.0);
    if (b < 0)
        b = 0;
    else if (b > 255)
        b = 255;

    sf::Color newColor = {
            static_cast<sf::Uint8>(r),
            static_cast<sf::Uint8>(g),
            static_cast<sf::Uint8>(b)
    };
    return newColor;
}

sf::Color RayTracer::DirectionalLight::AmbientLightCalculate(sf::Color& colorObject)
{
    return colorObject;
}
