/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** sceneBuilder
*/

#ifndef RAYTRACER_SCENEBUILDER_HPP
#define RAYTRACER_SCENEBUILDER_HPP

#include "raytracer.hpp"
#include "Camera.hpp"
#include "someStructsForTheParser.hpp"

using namespace RayTracer;

class sceneBuilder {
public:
    sceneBuilder() = default;
    ~sceneBuilder() = default;

    static Camera setCamera(const camera_t& structCamera);
    static Sphere addSphere(const sphere_t& sphere);
    static Plane addPlane(const plane_t& plane);
    static AmbientLighting setAmbientLighting(ambientL_t ambiant);
    static DirectionalLight addDirectionalLighting(directionalL_t directional);

};


#endif //RAYTRACER_SCENEBUILDER_HPP
