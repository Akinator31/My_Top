/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** fifth_line
*/

#include <ncurses.h>
#include <stdlib.h>
#include "fetch_data.h"

int draw_fifth_line(WINDOW *window)
{
    double total_swap_memory = fetch_total_swap_memory();
    double free_swap_memory = fetch_free_swap_memory();
    double used_swap_memory = fetch_used_swap_memory();
    double available_swap_memory = fetch_available_swap_memory();

    printw("MiB Swap:   %.1f total,", total_swap_memory);
    printw("   %.1f free,", free_swap_memory);
    printw("      %.1f used.", used_swap_memory);
    printw("   %.1f avail Mem\n\n", available_swap_memory);
}
