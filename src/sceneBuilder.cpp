/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** sceneBuilder
*/

#include "sceneBuilder.hpp"

Camera sceneBuilder::setCamera(const camera_t &structCamera)
{
    Camera cam = Camera(structCamera.origin, structCamera.width, structCamera.height);
    return cam;
}

Sphere sceneBuilder::addSphere(const sphere_t &sphere)
{
    Sphere s = Sphere(sphere.center, sphere.radius, sphere.color);
    return s;
}

Plane sceneBuilder::addPlane(const plane_t &plane)
{
    Plane p = Plane(plane.axis, plane.pos, plane.color);
    return p;
}

AmbientLighting sceneBuilder::setAmbientLighting(ambientL_t ambient)
{
    AmbientLighting ambientL = AmbientLighting(ambient.color, ambient.intensity);
    return ambientL;
}

DirectionalLight sceneBuilder::addDirectionalLighting(directionalL_t directional)
{
    DirectionalLight directionalL = DirectionalLight(directional.degree, directional.intensity, directional.z);
    return directionalL;
}
