/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** shmem_memory
*/

#include <stdlib.h>
#include "fetch_data.h"
#include "utils.h"

double fetch_shmem_memory(void)
{
    char *buffer = open_and_read_file("/proc/meminfo", 1024);
    double shmem_memory = atof(buffer + find_number(buffer, 616));

    free(buffer);
    return shmem_memory / 1024;
}
