/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sat, Mar, 2026                                                     *
 * Title           - G-OOP-400-MAR-4-1-arcade-4                                         *
 * Description     -                                                                    *
 *     libloader                                                                        *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *             ███████╗██████╗ ██╗████████╗███████╗ ██████╗██╗  ██╗                     *
 *             ██╔════╝██╔══██╗██║╚══██╔══╝██╔════╝██╔════╝██║  ██║                     *
 *             █████╗  ██████╔╝██║   ██║   █████╗  ██║     ███████║                     *
 *             ██╔══╝  ██╔═══╝ ██║   ██║   ██╔══╝  ██║     ██╔══██║                     *
 *             ███████╗██║     ██║   ██║   ███████╗╚██████╗██║  ██║                     *
 *             ╚══════╝╚═╝     ╚═╝   ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝                     *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#ifndef LIBLOADER_HPP
#define LIBLOADER_HPP

#include "IDisplayModule.hpp"
#include <string>

class LibraryLoader {
public:
    explicit LibraryLoader(const std::string &path) noexcept;
    ~LibraryLoader() noexcept;
    LibraryLoader(const LibraryLoader &) = delete;
    LibraryLoader &operator=(const LibraryLoader &) = delete;
    LibraryLoader(LibraryLoader &&other) noexcept;
    LibraryLoader &operator=(LibraryLoader &&other) noexcept;
    bool open();
    IDisplayModule *create();
    void destroy(IDisplayModule *m);
    void close();
    const std::string &path() const noexcept { return path_; }
private:
    void *handle_;
    std::string path_;
    using create_t = IDisplayModule *();
    using destroy_t = void(IDisplayModule *);
    create_t *create_fn_;
    destroy_t *destroy_fn_;
};

#endif
