/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** rectangle3D.hpp
*/

#ifndef RAYTRACER_RECTANGLE3D_HPP
    #define RAYTRACER_RECTANGLE3D_HPP

    #include "point3D.hpp"

namespace RayTracer {
    class Rectangle3D {
        public:
            Rectangle3D(Math::Point3D origin, Math::Vector3D bottom_side, Math::Vector3D left_side);

            Math::Point3D pointAt(double u, double v);

            Math::Point3D _origin;
            Math::Vector3D _bottom_side;
            Math::Vector3D _left_side;
    };
}

#endif
