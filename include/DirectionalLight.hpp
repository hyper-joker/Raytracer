/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** DirectionalLight.hpp
*/

#ifndef DIRECTIONALLIGHT_HPP_
	#define DIRECTIONALLIGHT_HPP_

    #include <SFML/Graphics.hpp>
    #include "ILight.hpp"
    #include "vector3D.hpp"

namespace RayTracer {
    class DirectionalLight : public ILight {
        public:
            DirectionalLight(double degree, double intensity, double z, sf::Color color = sf::Color::White);
            ~DirectionalLight() override = default;

            sf::Color applyLight(const Math::Point3D &point, const Math::Point3D &center, sf::Color color) override;
            sf::Color AmbientLightCalculate(sf::Color& colorObject) override;


        Math::Vector3D _direction;
            sf::Color _color;
            double _degree;
            double _intensity;
    };
}

#endif
