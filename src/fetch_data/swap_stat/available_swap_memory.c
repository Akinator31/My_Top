/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** available_swap_memory
*/

#include <stdlib.h>
#include "fetch_data.h"
#include "utils.h"

double fetch_available_swap_memory(void)
{
    return fetch_total_memory() - fetch_used_memory();
}
