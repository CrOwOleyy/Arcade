#include "libbar.hpp"
#include <cstdio>

extern "C"
{
    IDisplayModule *create_module()
    {
        return (new Bar());
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
    std::puts ("[libbar] Loading bar library ...");
}

__attribute__((destructor))
void lib_fini (void)
{
    std::puts ("[libbar] bar closing ...");
}
