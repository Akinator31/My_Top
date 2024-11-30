/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** available_memory
*/

#include <stdlib.h>
#include "fetch_data.h"
#include "utils.h"

double fetch_available_memory(void)
{
    char *buffer = open_and_read_file("/proc/meminfo", 256);
    double available_memory = atof(buffer + find_number(buffer, 56));

    free(buffer);
    return available_memory / 1024;
}
