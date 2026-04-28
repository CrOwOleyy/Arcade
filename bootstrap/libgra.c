/*
** EPITECH PROJECT, 2026
** G-OOP-400-MAR-4-1-arcade-4
** File description:
** libgra
*/

#include <stdio.h>

__attribute__((constructor))

void open_library(void)
{
    printf("[libgra] Loading gra library ...\n");
}


__attribute__((destructor))

void close_library(void)
{
    printf("[libgra] gra closing ...\n");
}

int myEntryPoint()
{
    printf ("[libgra] Entry point for gra !\n");
    return 0;
}