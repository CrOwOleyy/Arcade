/*
** EPITECH PROJECT, 2026
** G-OOP-400-MAR-4-1-arcade-4
** File description:
** libbar
*/

#include <stdio.h>

__attribute__((constructor))

void open_library(void)
{
    printf("[libbar] Loading bar library ...\n");
}


__attribute__((destructor))

void close_library(void)
{
    printf("[libbar] bar closing ...\n");
}

int myEntryPoint()
{
    printf ("[libbar] Entry point for bar !\n");
    return 0;
}