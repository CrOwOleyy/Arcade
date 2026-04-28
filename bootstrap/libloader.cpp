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

#include "libloader.hpp"
#include <dlfcn.h>
#include <iostream>

LibraryLoader::LibraryLoader(const std::string &path) noexcept : handle_(nullptr), path_(path), create_fn_(nullptr), destroy_fn_(nullptr)
{
}

LibraryLoader::~LibraryLoader() noexcept
{
    close();
}

LibraryLoader::LibraryLoader(LibraryLoader &&other) noexcept : handle_(other.handle_), path_(std::move(other.path_)), create_fn_(other.create_fn_), destroy_fn_(other.destroy_fn_)
{
    other.handle_ = nullptr;
    other.create_fn_ = nullptr;
    other.destroy_fn_ = nullptr;
}

LibraryLoader &LibraryLoader::operator=(LibraryLoader &&other) noexcept
{
    if (this != &other) {
        close();
        handle_ = other.handle_;
        path_ = std::move(other.path_);
        create_fn_ = other.create_fn_;
        destroy_fn_ = other.destroy_fn_;
        other.handle_ = nullptr;
        other.create_fn_ = nullptr;
        other.destroy_fn_ = nullptr;
    }
    return *this;
}

bool LibraryLoader::open()
{
    handle_ = dlopen(path_.c_str(), RTLD_NOW);
    if (!handle_) {
        std::cerr << "dlopen(" << path_ << "): " << dlerror() << '\n';
        return false;
    }
    create_fn_ = reinterpret_cast<create_t *>(dlsym(handle_, "create_module"));
    destroy_fn_ = reinterpret_cast<destroy_t *>(dlsym(handle_, "destroy_module"));
    if (!create_fn_) {
        std::cerr << "dlsym(create_module): " << dlerror() << '\n';
        dlclose(handle_);
        handle_ = nullptr;
        return false;
    }
    return true;
}

IDisplayModule *LibraryLoader::create()
{
    if (!create_fn_)
        return nullptr;
    return create_fn_();
}

void LibraryLoader::destroy(IDisplayModule *m)
{
    if (destroy_fn_ && m)
        destroy_fn_(m);
}

void LibraryLoader::close()
{
    if (handle_) {
        dlclose(handle_);
        handle_ = nullptr;
    }
    create_fn_ = nullptr;
    destroy_fn_ = nullptr;
}
