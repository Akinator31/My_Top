/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** fourth_line
*/

#include <ncurses.h>
#include <dirent.h>
#include <stdlib.h>
#include "fetch_data.h"

int show_swap_stat(WINDOW *window, double *result)
{
    printw("MiB Swap:   %.1f total,", result[TOTAL_SWAP_MEMORY] / 1024);
    printw("   %.1f free,", result[FREE_SWAP_MEMORY] / 1024);
    printw("      %.1f used.", result[USED_SWAP_MEMORY] / 1024);
    printw("   %.1f avail Mem\n\n", result[AVAILABLE_SWAP_MEMORY] / 1024);
}

int show_mem_stat(WINDOW *window)
{
    double *result = get_memory_stat("/proc/meminfo");

    printw("MiB Mem :  %.1f total,", result[7] / 1024);
    printw("  %.1f free,", result[3] / 1024);
    printw("   %.1f used,", result[8]);
    printw("   %.1f buff/cache\n", (result[1] / 1024) +
        (result[2] / 1024) + (result[6] / 1024));
    show_swap_stat(window, result);
    free(result);
}
