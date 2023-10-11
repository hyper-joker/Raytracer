/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
**
*/

#ifndef RAYTRACER_CAMERA_HPP
#define RAYTRACER_CAMERA_HPP

#define SCREEN_X (origin.x - (width / 200))
#define SCREEN_Y (origin.y - (height / 200))
#define SCREEN_Z (origin.z - 1)

#include "Ray.hpp"
#include "rectangle3D.hpp"

namespace RayTracer {
    class Camera {
    public:
        std::pair<int, int> screenSize;
        explicit Camera(const Math::Point3D &origin = {0,0,0}, const int &width = 0, const int &height = 0);

        Ray ray(double u, double v);
    private:

        Rectangle3D _screen;
        Math::Point3D _origin;
    };
}

#endif //RAYTRACER_CAMERA_HPP
