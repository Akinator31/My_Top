/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** get_filepath
*/

#include <stdlib.h>
#include "my.h"

char *get_filepath(char *part_one, char *part_two, char *part_three,
    int size_filepath)
{
    char *filepath = malloc(sizeof(char) * size_filepath);

    my_memset(filepath, '\0', sizeof(char) * size_filepath);
    my_strcpy(filepath, part_one);
    my_strcat(filepath, part_two);
    my_strcat(filepath, part_three);
    return filepath;
}
