/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** shmemhugepage_memory
*/

#include <stdlib.h>
#include "fetch_data.h"
#include "utils.h"

double fetch_shmemhugepage_memory(void)
{
    char *buffer = open_and_read_file("/proc/meminfo", 1500);
    double shmemhugepage = atof(buffer + find_number(buffer, 1148));

    free(buffer);
    return shmemhugepage / 1024;
}
