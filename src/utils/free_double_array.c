/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** free_double_array
*/

#include <stdlib.h>

void free_double_array(char **data)
{
    for (int i = 0; data[i] != NULL; i++) {
        free(data[i]);
    }
    free(data);
}
