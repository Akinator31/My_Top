/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** find_number
*/

#include <stdio.h>

int my_is_a_number(char actual_char)
{
    if ((actual_char >= '0') && (actual_char <= '9'))
        return 1;
    return 0;
}

int find_number(char *buffer, int index)
{
    while (my_is_a_number(buffer[index]) != 1)
        index++;
    return index;
}
