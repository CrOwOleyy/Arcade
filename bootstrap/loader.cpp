/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sat, Mar, 2026                                                     *
 * Title           - G-OOP-400-MAR-4-1-arcade-4                                         *
 * Description     -                                                                    *
 *     loader                                                                           *
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

#include "IDisplayModule.hpp"
#include "libloader.hpp"
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> libs = { "./libfoo.so", "./libbar.so", "./libgra.so" };
    std::vector<LibraryLoader> loaders;
    std::vector<IDisplayModule *> modules;

    for (auto &path : libs) {
        loaders.emplace_back(path);
        if (!loaders.back().open())
            return (1);
        IDisplayModule *m = loaders.back().create();
        if (!m) {
            std::cerr << "create_module failed for " << path << '\n';
            return (1);
        }
        modules.push_back(m);
    }
    for (auto m : modules) {
        m->init();
        std::cout << "[" << m->getName() << "] entry called\n";
        m->stop();
    }
    for (size_t i = 0 ; i < loaders.size() ; ++i) {
        loaders[i].destroy(modules[i]);
        loaders[i].close();
    }
    return (0);
}
