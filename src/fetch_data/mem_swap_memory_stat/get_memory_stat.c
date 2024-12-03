/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** get_memory_stat
*/

#include <stdlib.h>
#include "fetch_data.h"
#include "utils.h"

double *get_memory_stat(char *filepath)
{
    char *buffer = open_and_read_file(filepath, 1500);
    double *result = malloc(sizeof(double) * 13);

    result[AVAILABLE_MEMORY] = atof(buffer + find_number(buffer, 56));
    result[BUFFER_MEMORY] = atof(buffer + find_number(buffer, 84));
    result[CACHE_MEMORY] = atof(buffer + find_number(buffer, 112));
    result[FREE_MEMORY] = atof(buffer + find_number(buffer, 44));
    result[SHMEM_MEMORY] = atof(buffer + find_number(buffer, 616));
    result[SHMEMHUGEPAGE] = atof(buffer + find_number(buffer, 1148));
    result[SUNRECLAIMED_MEMORY] = atof(buffer + find_number(buffer, 700));
    result[TOTAL_MEMORY] = atof(buffer + find_number(buffer, 16));
    result[USED_MEMORY] = (result[7] / 1024) - (result[0] / 1024);
    result[AVAILABLE_SWAP_MEMORY] = result[TOTAL_MEMORY]
        - (result[7] - result[0]);
    result[FREE_SWAP_MEMORY] = atof(buffer + find_number(buffer, 420));
    result[TOTAL_SWAP_MEMORY] = atof(buffer + find_number(buffer, 392));
    result[USED_SWAP_MEMORY] = result[TOTAL_SWAP_MEMORY]
        - result[FREE_SWAP_MEMORY];
    free(buffer);
    return result;
}
