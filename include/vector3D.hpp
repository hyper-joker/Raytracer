/*
** EPITECH PROJECT, 2023
** bs_raytracer
** File description:
**
*/

#ifndef BS_RAYTRACER_VECTOR3D_HPP
#define BS_RAYTRACER_VECTOR3D_HPP

namespace Math {
    class Vector3D {
    public:
        Vector3D();
        Vector3D(double x, double y, double z);
        Vector3D(const Vector3D& other);
        Vector3D(Vector3D&& other);

        Vector3D& operator=(const Vector3D& other);
        Vector3D& operator=(Vector3D&& other);
        double length() const;
        double dot(const Vector3D& other) const;
        Vector3D operator+(const Vector3D& other) const;
        Vector3D& operator+=(const Vector3D& other);
        Vector3D operator-(const Vector3D& other) const;
        Vector3D& operator-=(const Vector3D& other);
        Vector3D operator*(double scalar) const;
        Vector3D& operator*=(double scalar);
        Vector3D operator/(double scalar) const;
        Vector3D& operator/=(double scalar);

        double x;
        double y;
        double z;
    };
}

#endif //BS_RAYTRACER_VECTOR3D_HPP
