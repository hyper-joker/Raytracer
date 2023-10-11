/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
**
*/

#include <cstring>
#include <iostream>

#include "errors.hpp"
#include "raytracer.hpp"
#include "someStructsForTheParser.hpp"
#include "sceneBuilder.hpp"

Raytracer::Raytracer() = default;

void Raytracer::checkTheParams(int ac, char **av) {
    try {
        if (ac != 2)
            usageWithOrWithoutError(true);
        if (ac == 2 && strcmp(av[1], "--help") == 0)
            usageWithOrWithoutError(false);
    } catch (const std::exception& excep) {
        std::cerr << "Error: " << excep.what() << std::endl;
        exit(84);
    }
}

void Raytracer::usageWithOrWithoutError(bool error) {
    std::cout << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
    std::cout << "\tSCENE_FILE: scene configuration" << std::endl;

    if (error)
        throw Errors();
}

void Raytracer::raytracerMain(char *path) {
    Parser parser = Parser(path);
    parser.parse_file();
    _camera = sceneBuilder::setCamera(parser._camera);

    addPrimitivesToScene(parser._primitives);
    setupLights(parser._lights.ambient, parser._lights.directionals);
    raytracerLoop(getFilename(path));
}


void Raytracer::addPrimitivesToScene(primitives_t primitives) {
    int planes = 0;
    int spheres = 0;

    if (primitives.planes.empty()) {
        planes = -1;
        std::cout << "no planes to add" << std::endl;
    }
    if (primitives.spheres.empty()) {
        std::cout << "no spheres to add" << std::endl;
        spheres = -1;
    }
    if (spheres == 0 && planes == 0) {
        addBothPrim(primitives.spheres, primitives.planes);
    } else if (spheres == -1 && planes == 0) {
        addPlaneOnly(primitives.planes);
    } else if (spheres == 0) {
        addSphereOnly(primitives.spheres);
    }
}

bool comparePosValue(const plane_t & a, const plane_t& b) {
    return a.pos < b.pos;
}

bool compareZValue(const sphere_t & a, const sphere_t& b) {
    return a.center.z < b.center.z;
}

void Raytracer::addSphereOnly(vector<sphere_t> spheres) {
    std::sort(spheres.begin(), spheres.end(), compareZValue);
    for (auto &sphere: spheres) {
        std::shared_ptr<RayTracer::Sphere> sp = std::make_shared<RayTracer::Sphere>(sphere.center, sphere.radius, sphere.color);
        _primitives.push_back(sp);
    }
}

void Raytracer::addPlaneOnly(vector<plane_t> planes) {
    std::sort(planes.begin(), planes.end(), comparePosValue);
    for (auto &plane : planes) {
        std::shared_ptr<RayTracer::Plane> pl = std::make_shared<RayTracer::Plane>(plane.axis, plane.pos, plane.color);
        _primitives.push_back(pl);
    }
}

void Raytracer::addBothPrim(vector<sphere_t> spheres, vector<plane_t> planes) {
    addSphereOnly(spheres);
    addPlaneOnly(planes);
}

void Raytracer::raytracerLoop(const std::string &filename)
{
    std::string file = filename + ".ppm";
    sf::RenderWindow window(sf::VideoMode(_camera.screenSize.first, _camera.screenSize.second), "Raytracer - " + filename, sf::Style::Close);

    createPpmFile(file);
    addContentToPpmFile("P3");
    addContentToPpmFile(std::to_string(_camera.screenSize.first) + " " + std::to_string(_camera.screenSize.second));
    addContentToPpmFile("255");
    while (window.isOpen()) {
        handleEvents(window);
        for (int i_y = 0; i_y < _camera.screenSize.second && !_isRayTraced; i_y++) {
            for (int i_x = 0; i_x < _camera.screenSize.first; i_x++) {
                handleEvents(window);
                double u = static_cast<double>(i_x) / (_camera.screenSize.first - 1);
                double v = static_cast<double>(i_y) / (_camera.screenSize.second - 1);
                RayTracer::Ray r = _camera.ray(u, v);
                handleDrawing(window, i_y, i_x, r);
                if (window.isOpen())
                    window.display();
            }
        }
        _isRayTraced = true;
    }
}

void Raytracer::handleDrawing(sf::RenderWindow &window, int i_y, int i_x, const RayTracer::Ray &r)
{
    for (auto &prim : _primitives) {
        if (prim->hits(r)) {
            sf::Color color = prim->getColor();
            for (auto &lt : _lights) {
                color = lt->AmbientLightCalculate(color);
                color = lt->applyLight(prim->impact(r), prim->getPoint(), color);
            }
            drawPixel(window, i_x, i_y, color);
            addContentToPpmFile(std::to_string(color.r) + " " + std::to_string(color.g) + " " + std::to_string(color.b));
            return;
        }
    }
    drawPixel(window, i_x, i_y, {0, 0, 0});
    addContentToPpmFile("0 0 0");
}

void Raytracer::drawPixel(sf::RenderWindow &window, int x, int y, const sf::Color &color)
{
    if (window.isOpen()) {
        sf::Vertex vertices[4];
        vertices[0].position = sf::Vector2f (static_cast<float>(x), static_cast<float>(y));
        vertices[1].position = sf::Vector2f (static_cast<float>(x) + 4, static_cast<float>(y));
        vertices[2].position = sf::Vector2f (static_cast<float>(x) + 4, static_cast<float>(y) + 4);
        vertices[3].position = sf::Vector2f (static_cast<float>(x), static_cast<float>(y) + 4);
        for (auto & vertice : vertices) {
            vertice.color = color;
        }
        window.draw(vertices, 4, sf::Quads);
    }
}

void Raytracer::handleEvents(sf::RenderWindow &window)
{
    sf::Event event {};

    while (window.isOpen() && window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.clear();
            window.close();
        }
    }
}

void Raytracer::createPpmFile(std::string &filename)
{
    _file = std::ofstream(filename);

    if (_file.is_open()) {
        _file.clear();
    }
}

void Raytracer::addContentToPpmFile(const std::string& content)
{
    if (_file.is_open()) {
        _file << content << "\n";
    }
}

std::string Raytracer::getFilename(const char *path)
{
    std::string filename = path;
    std::size_t found = filename.find_last_of("/\\");

    if (found != std::string::npos)
        filename = filename.substr(found + 1);
    found = filename.find_last_of(".");
    if (found != std::string::npos)
        filename = filename.substr(0, found);
    return filename;
}

void Raytracer::setupLights(ambientL_t ambient, vector<directionalL_t> directionals)
{
    if (ambient.intensity != -1) {
        std::shared_ptr<RayTracer::AmbientLighting> amb = std::make_shared<RayTracer::AmbientLighting>(ambient.color, ambient.intensity);
        _lights.push_back(amb);
    }
    if (!directionals.empty()) {
        for (auto dls : directionals) {
            std::shared_ptr<RayTracer::DirectionalLight> dl = std::make_shared<RayTracer::DirectionalLight>(dls.degree, dls.intensity, dls.z, dls.color);
            _lights.push_back(dl);
        }
    }
}
