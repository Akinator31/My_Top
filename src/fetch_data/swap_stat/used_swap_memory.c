/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** used_swap_memory
*/

#include <stdlib.h>
#include "fetch_data.h"
#include "utils.h"

double fetch_used_swap_memory(void)
{
    return fetch_total_swap_memory() - fetch_free_swap_memory();
}
