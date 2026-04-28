/*
** EPITECH PROJECT, 2026
** G-OOP-400-MAR-4-1-arcade-4
** File description:
** loader
*/

/*
** EPITECH PROJECT, 2026
** G-OOP-400-MAR-4-1-arcade-4
** File description:
** loader
*/

#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

typedef int (*entry_t)(void);

int main(void)
{
    const char *libs[] = {"./libfoo.so", "./libbar.so", "./libgra.so"};
    void *handles[3] = {0};

    for (int i = 0; i < 3; i++) {
        handles[i] = dlopen(libs[i], RTLD_NOW);
        if (!handles[i]) {
            fprintf(stderr, "Error loading %s: %s\n", libs[i], dlerror());
            return 1;
        }
    }
    for (int i = 0; i < 3; i++) {
        entry_t entry = (entry_t)dlsym(handles[i], "myEntryPoint");
        if (!entry) {
            fprintf(stderr, "dlsym: %s\n", dlerror());
            return 1;
        }
        entry();
    }
    for (int i = 0; i < 3; i++) {
        dlclose(handles[i]);
    }
    return 0;
}