/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** copy_until
*/

#include "my.h"

void copy_until(char *src, char *dest, char to_find)
{
    for (int i = 0; (src[i] != to_find) || (src[i] != to_find); i++) {
        dest[i] = src[i];
    }
}
