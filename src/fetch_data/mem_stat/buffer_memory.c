/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** buffer_memory
*/

#include <stdlib.h>
#include "fetch_data.h"
#include "utils.h"

double fetch_buffer_memory(void)
{
    char *buffer = open_and_read_file("/proc/meminfo", 256);
    double buffer_memory = atof(buffer + find_number(buffer, 84));

    free(buffer);
    return buffer_memory / 1024;
}
