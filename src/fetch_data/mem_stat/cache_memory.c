/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** cache_memory
*/

#include <stdlib.h>
#include "fetch_data.h"
#include "utils.h"

double fetch_cache_memory(void)
{
    char *buffer = open_and_read_file("/proc/meminfo", 256);
    double cache_memory = atof(buffer + find_number(buffer, 112));

    free(buffer);
    return cache_memory / 1024;
}
