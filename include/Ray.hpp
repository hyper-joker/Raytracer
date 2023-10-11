/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
**
*/

#ifndef RAYTRACER_RAY_HPP
#define RAYTRACER_RAY_HPP

#include "point3D.hpp"

namespace RayTracer {
    class Ray {
    public:
        Ray();

        Ray(Math::Point3D origin, Math::Vector3D distance);

        Ray(const Ray &other);

        Ray(Ray &&other) noexcept;

        Ray &operator=(const Ray &other);

        Ray &operator=(Ray &&other) noexcept;

        Math::Point3D _origin;
        Math::Vector3D _distance;
    };

}

#endif //RAYTRACER_RAY_HPP
