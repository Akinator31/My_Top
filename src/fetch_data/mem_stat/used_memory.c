/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** used_memory
*/

#include <stdlib.h>
#include "fetch_data.h"
#include "utils.h"

double fetch_used_memory(void)
{
    double total_memory = fetch_total_memory();
    double free_memory = fetch_free_memory();

    return total_memory - fetch_available_memory();
}
