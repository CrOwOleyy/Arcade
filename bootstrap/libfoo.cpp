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

#include "libfoo.hpp"
#include <cstdio>

extern "C"
{
    IDisplayModule *create_module()
    {
        return (new Foo());
    }
}

extern "C"
{
    void destroy_module(IDisplayModule *m)
    {
        delete m;
    }
}

__attribute__((constructor))
void lib_init (void)
{
    std::puts ("[libfoo] Loading foo library ...");
}

__attribute__((destructor))
void lib_fini (void)
{
    std::puts ("[libfoo] foo closing ...");
}
