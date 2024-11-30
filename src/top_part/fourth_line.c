/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** fourth_line
*/

#include <ncurses.h>
#include <dirent.h>
#include "../../include/fetch_data.h"

int draw_fourth_line(WINDOW *window)
{
    printw("MiB Mem :  %.1f total,", fetch_total_memory());
    printw("  %.1f free,", fetch_free_memory());
    printw("   %.1f used,", fetch_used_memory());
    printw("   %.1f buff/cache\n", fetch_buffer_memory() +
        fetch_cache_memory() + fetch_sunreclaimed_memory());
}
