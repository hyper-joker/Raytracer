/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** structs
*/

#include <vector>
#include <iostream>
#include "point3D.hpp"
#include "IPrimitives.hpp"
#include <SFML/Graphics/Color.hpp>

#ifndef RAYTRACER_SOMESTRUCTSFORTHEPARSER_HPP
#define RAYTRACER_SOMESTRUCTSFORTHEPARSER_HPP

using namespace std;

typedef struct camera_s {
    int width;
    int height;
    Math::Point3D origin;
} camera_t;

typedef struct sphere_s {
    Math::Point3D center;
    double radius;
    sf::Color color;
} sphere_t;

typedef struct plane_s {
    string axis;
    sf::Color color;
    int pos;
} plane_t;

typedef struct primitives_s {
    vector<sphere_t> spheres;
    vector<plane_t> planes;
} primitives_t;

typedef struct ambientL_s {
    sf::Color color;
    double intensity;
} ambientL_t;

typedef struct directionalL_s {
    double degree;
    double intensity;
    double z;
    sf::Color color;
} directionalL_t;

typedef struct lights_s {
    ambientL_t ambient;
    vector<directionalL_t> directionals;
} lights_t;

#endif //RAYTRACER_SOMESTRUCTSFORTHEPARSER_HPP
