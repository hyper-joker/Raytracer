/*
** EPITECH PROJECT, 2023
** point3D.hpp
** File description:
** point3D.hpp
*/
#ifndef BS_RAYTRACER_POINT3D_HPP
    #define BS_RAYTRACER_POINT3D_HPP

#include "vector3D.hpp"

namespace Math {
    class Point3D {
        public:
            Point3D();
            Point3D(double x, double y, double z);
            Point3D(const Point3D& other);
            Point3D(Point3D&& other) noexcept;

            Point3D &operator=(const Point3D& other);
            Point3D& operator=(Point3D&& other) noexcept ;
            Point3D operator+(const Math::Vector3D& vector) const;
            Point3D &operator+=(Math::Vector3D& vector);
            Point3D operator-(const Point3D& vector) const;

            double x;
            double y;
            double z;
    };
}

#endif
