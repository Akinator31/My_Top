/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** total_swap_memory
*/

#include <stdlib.h>
#include "fetch_data.h"
#include "utils.h"

double fetch_total_swap_memory(void)
{
    char *buffer = open_and_read_file("/proc/meminfo", 1024);
    double total_swap_memory = atof(buffer + find_number(buffer, 392));

    free(buffer);
    return total_swap_memory / 1024;
}
