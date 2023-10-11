/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
**
*/

#ifndef RAYTRACER_PARSER_HPP
#define RAYTRACER_PARSER_HPP

#include <iostream>
#include <libconfig.h++>

#include "point3D.hpp"
#include "someStructsForTheParser.hpp"

using namespace std;

class Parser {
public:

    camera_t _camera;
    primitives_t _primitives;
    lights_t _lights;
    libconfig::Config _config;
    explicit Parser(char *path);

    ~Parser() = default;
    void parse_file();
private:
    string _path;

    void readFile();
    void getCamInfo();

    void setupSphereStruct(vector<sphere_t> &spheres);
    void setupPlaneStruct(vector<plane_t> &planes_v);
    static sphere_t getOneSphere(const libconfig::Setting &sphere);
    static plane_t getOnePlane(const libconfig::Setting &plane);
    void getAmbientL(ambientL_t &ambient);
    void getDirectional(vector<directionalL_t> &directionalLights);
    static directionalL_t getOneDirL(const libconfig::Setting &dir);

};

#endif //RAYTRACER_PARSER_HPP
