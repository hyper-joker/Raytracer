/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
**
*/

#ifndef RAYTRACER_ERRORS_HPP
#define RAYTRACER_ERRORS_HPP

#include <exception>
#include <iostream>
#include <utility>

class Errors : public std::exception {
private:
    std::string message;

public:
    explicit Errors(std::string  msg = "") : message(std::move(msg)) {}

    [[nodiscard]] const char* what() const noexcept override;

};


#endif //RAYTRACER_ERRORS_HPP
