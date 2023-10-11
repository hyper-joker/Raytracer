/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
**
*/

#include "parser.hpp"

Parser::Parser(char *path)
{
    _path =  path;
}

void Parser::readFile() {
    try {
        _config.readFile (_path.c_str());
        std::cout << "read  file ok" << std::endl;
    } catch (libconfig::FileIOException &e){
        cerr << "FileIOException occurred. Could not read \"" << _path << "\" Pay attention to the path give !!"  << endl;
        exit (84);
    } catch (libconfig::ParseException &e){
        cerr << "Parse error at " << e.getFile() << ":" << e.getLine() << " - " << e.getError() << endl;
        exit(84);
    }
}

void Parser::parse_file()
{
    readFile();
    getCamInfo();
    setupSphereStruct(_primitives.spheres);
    setupPlaneStruct(_primitives.planes);
    getAmbientL(_lights.ambient);
    getDirectional(_lights.directionals);
}

void Parser::getCamInfo()
{
    try {
        _camera.height = _config.lookup("camera.resolution.height");
        _camera.width = _config.lookup("camera.resolution.width");
        _camera.origin.x = _config.lookup("camera.position.x");
        _camera.origin.y = _config.lookup("camera.position.y");
        _camera.origin.z = _config.lookup("camera.position.z");
    } catch (libconfig::SettingNotFoundException  &e) {
        std::cerr << "No  camera  found" << std::endl;
        exit(84);
    }  catch (libconfig::SettingTypeException &e) {
        std::cerr << "Type mismatch for camera" << std::endl;
        exit(84);
    }
}

void Parser::setupPlaneStruct(vector<plane_t> &planes_v)
{
    const libconfig::Setting& root = _config.getRoot();
    try {
        const libconfig::Setting &p = root["primitives"];
        const libconfig::Setting &planes = p["planes"];
        for(int i = 0; i < planes.getLength(); ++i) {
            const libconfig::Setting &plane = planes[i];
            planes_v.push_back(getOnePlane(plane));
        }
    } catch (libconfig::SettingNotFoundException  &e) {
        std::cerr << "No  plane  found or options" << std::endl;
        exit(84);
    }  catch (libconfig::SettingTypeException &e) {
        std::cerr << "Type mismatch for plane" << std::endl;
        exit(84);

    }
}

void Parser::setupSphereStruct(vector<sphere_t> &spheres_v)
{
    const libconfig::Setting& root = _config.getRoot();
    try {
        const libconfig::Setting &p = root["primitives"];
        const libconfig::Setting &spheres = p["spheres"];
        for(int i = 0; i < spheres.getLength(); ++i) {
            const libconfig::Setting &sphere = spheres[i];
            spheres_v.push_back(getOneSphere(sphere));
        }
    } catch (libconfig::SettingNotFoundException  &e) {
        std::cerr << "No  sphere  found or options" << std::endl;
        exit(84);
    }  catch (libconfig::SettingTypeException &e) {
        std::cerr << "Type mismatch for sphere" << std::endl;
        exit(84);
    }
}

sphere_t Parser::getOneSphere(const libconfig::Setting &sphere)
{
    sphere_t new_sphere;
    int r = sphere.lookup("color.r");
    int g = sphere.lookup("color.g");
    int b = sphere.lookup("color.b");

    new_sphere.center = {sphere.lookup("x"), sphere.lookup("y"),sphere.lookup("z")};
    new_sphere.radius = sphere.lookup("r");
    new_sphere.color.r = r;
    new_sphere.color.g = g;
    new_sphere.color.b = b;
    return new_sphere;
}

plane_t Parser::getOnePlane(const libconfig::Setting &plane)
{
    plane_t new_plane;
    int r = plane.lookup("color.r");
    int g = plane.lookup("color.g");
    int b = plane.lookup("color.b");

    new_plane.axis = plane.lookup("axis").c_str();
    new_plane.pos = plane.lookup("position");
    new_plane.color.r = r;
    new_plane.color.g = g;
    new_plane.color.b = b;
    return new_plane;
}

void Parser::getAmbientL(ambientL_t &ambient)
{
    try {
        int r = _config.lookup("lights.ambient.color.r");
        int g = _config.lookup("lights.ambient.color.g");
        int b = _config.lookup("lights.ambient.color.b");

        ambient.intensity = _config.lookup("lights.ambient.intensity");
        ambient.color.r = r;
        ambient.color.g = g;
        ambient.color.b = b;
    } catch (libconfig::SettingNotFoundException  &e) {
        std::cerr << "No  ambient light or missing options" << std::endl;
        exit(84);
    }  catch (libconfig::SettingTypeException &e) {
        std::cerr << "Type mismatch for ambient light" << std::endl;
        exit(84);
    }
}

void Parser::getDirectional(vector<directionalL_t> &directionalLights)
{
    const libconfig::Setting& root = _config.getRoot();
    try {
        const libconfig::Setting &lights = root["lights"];
        const libconfig::Setting &directionals = lights["directional"];
        for(int i = 0; i < directionals.getLength(); ++i) {
            const libconfig::Setting &dir = directionals[i];
            directionalLights.push_back(getOneDirL(dir));
        }
    } catch (libconfig::SettingNotFoundException  &e) {
        std::cerr << "No  directional light  found or missing some options" << std::endl;
        exit(84);
    }  catch (libconfig::SettingTypeException &e) {
        std::cerr << "Type mismatch for directional light" << std::endl;
        exit(84);
    }
}

directionalL_t Parser::getOneDirL(const libconfig::Setting &dir)
{
    directionalL_t newDir;
    int r = dir.lookup("color.r");
    int g = dir.lookup("color.g");
    int b = dir.lookup("color.b");

    newDir.intensity = dir.lookup("intensity");
    newDir.degree = dir.lookup("degree");
    newDir.z = dir.lookup("z");

    if (newDir.z > 0 || newDir.z < -1)
        newDir.z = 0;
    newDir.color.r = r;
    newDir.color.g = g;
    newDir.color.b = b;
    return newDir;
}
