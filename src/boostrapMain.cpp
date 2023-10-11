/*
** EPITECH PROJECT, 2023
** main.cpp
** File description:
** main.cpp
*/

#include "../include/bootstrapMain.hpp"
#include "Sphere.hpp"
#include "Camera.hpp"
#include "Plane.hpp"

#include <utility>

void write_color(sf::Color color)
{
    std::cout << color.x << " " << color.y << " " << color.z << std::endl;
}

int main ()
{
    int imgHeight = 600;
    int imgWidth = 800;
    RayTracer::Camera cam({0, 0, 0}, imgWidth, imgHeight);
    RayTracer::Sphere s(sf::Point3D(0, 0, -1), 0.5);
    RayTracer::Plane p("Z", -20, {0, 0, 0}, sf::Color(0, 255, 0));

    std::cout << "P3" << std::endl;
    std::cout << imgWidth << " " << imgHeight << std::endl;
    std::cout << "255" << std::endl;
    for (int i_y = 0; i_y < imgHeight; i_y++) {
        for (int i_x = 0; i_x < imgWidth; i_x++) {
            double u = static_cast<double>(i_x) / imgWidth;
            double v = static_cast<double>(i_y) / imgHeight;
            RayTracer::Ray r = cam.ray(u, v);
            if (s.hits(r)) {
                write_color({255, 0, 0});
            } else if (p.hits(r)) {
                write_color(p._color);
            } else {
                write_color({0, 0, 255});
            }
        }
    }
}
