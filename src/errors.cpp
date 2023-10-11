/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
**
*/

#include "errors.hpp"

const char* Errors::what() const noexcept {
    return message.c_str();
}
