/*
** EPITECH PROJECT, 2026
** G-OOP-400-MAR-4-1-arcade-4
** File description:
** libfoo
*/

#include <stdio.h>

__attribute__((constructor))

void open_library(void)
{
    printf("[libfoo] Loading foo library ...\n");
}


__attribute__((destructor))

void close_library(void)
{
    printf("[libfoo] foo closing ...\n");
}

int myEntryPoint()
{
    printf ("[libfoo] Entry point for foo !\n");
    return 0;
}