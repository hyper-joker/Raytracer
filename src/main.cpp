/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** main.cpp
*/

#include "raytracer.hpp"

int main(int ac, char **av)
{
    Raytracer raytracer = Raytracer();

    Raytracer::checkTheParams(ac, av);
    raytracer.raytracerMain(av[1]);
    return 0;
}
