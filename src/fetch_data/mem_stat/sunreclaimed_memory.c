/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** sunreclaimed_memory
*/

#include <stdlib.h>
#include "fetch_data.h"
#include "utils.h"

double fetch_sunreclaimed_memory(void)
{
    char *buffer = open_and_read_file("/proc/meminfo", 1024);
    double sunreclaimed_memory = atof(buffer + find_number(buffer, 700));

    free(buffer);
    return sunreclaimed_memory / 1024;
}
