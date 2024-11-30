/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** free_memory
*/

#include <stdlib.h>
#include "fetch_data.h"
#include "utils.h"

double fetch_free_memory(void)
{
    char *buffer = open_and_read_file("/proc/meminfo", 256);
    double total_memory = atof(buffer + find_number(buffer, 44));

    free(buffer);
    return total_memory / 1024;
}
