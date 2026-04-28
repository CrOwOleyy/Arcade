/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sat, Mar, 2026                                                     *
 * Title           - G-OOP-400-MAR-4-1-arcade-4                                         *
 * Description     -                                                                    *
 *     libfoo                                                                           *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *         ░        ░       ░░        ░        ░        ░░      ░░  ░░░░  ░             *
 *         ▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒  ▒▒▒▒  ▒             *
 *         ▓      ▓▓▓       ▓▓▓▓▓  ▓▓▓▓▓▓▓  ▓▓▓▓      ▓▓▓  ▓▓▓▓▓▓▓        ▓             *
 *         █  ███████  ██████████  ███████  ████  ███████  ████  █  ████  █             *
 *         █        █  ███████        ████  ████        ██      ██  ████  █             *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#ifndef LIBFOO_HPP
#define LIBFOO_HPP

#include "IDisplayModule.hpp"
#include <string>
#include <iostream>

class Foo : public IDisplayModule {
    std::string name{"libfoo"};
public:
    Foo() = default;
    ~Foo() override = default;
    void init() override { std::cout << "[libfoo] Foo: graphics subsystem started\n"; };
    void stop() override { std::cout << "[libfoo] Foo: graphics subsystem stopped\n"; };
    const std::string &getName() const override { return name; };
};

#endif
