/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
**
*/

#ifndef RAYTRACER_RAYTRACER_HPP
#define RAYTRACER_RAYTRACER_HPP

#include <fstream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "parser.hpp"

#include "Camera.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "DirectionalLight.hpp"
#include "AmbientLighting.hpp"

class Raytracer {
public:
    Raytracer();
    ~Raytracer() = default;

    static void checkTheParams(int ac, char **av);
    void raytracerMain(char *path);
    void raytracerLoop(const std::string& filename);
    static void drawPixel(sf::RenderWindow &window, int x, int y, const sf::Color &color);
    static void handleEvents(sf::RenderWindow &window);
    void handleDrawing(sf::RenderWindow &window, int i_y, int i_x, const RayTracer::Ray &r);
    void createPpmFile(std::string &filename);
    void addContentToPpmFile(const std::string& content);
    static std::string getFilename(const char *path);
    void setupLights(ambientL_t ambient, vector<directionalL_t> directionals);

    std::ofstream _file;
    bool _isRayTraced = false;

private:
    Camera _camera;
    vector<std::shared_ptr<IPrimitives>> _primitives;
    vector<std::shared_ptr<ILight>> _lights;

    static void usageWithOrWithoutError(bool error);
    void addPrimitivesToScene(primitives_t primitives);
    void addBothPrim(vector<sphere_t> spheres, vector<plane_t> planes);
    void addSphereOnly(vector<sphere_t> spheres);
    void addPlaneOnly(vector<plane_t> planes);
};


#endif //RAYTRACER_RAYTRACER_HPP
