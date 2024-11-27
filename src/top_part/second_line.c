/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** second_line
*/

#include <ncurses.h>
#include <dirent.h>
#include "../../include/fetch_data.h"

int draw_second_line(WINDOW *window)
{
    int total_process = fetch_total_process();

    printw("Tasks:   %d total,   %d running,",
        total_process, fetch_running_process());
    printw("   %d sleeping,   %d stopped,",
        fetch_sleeping_process(), fetch_stopped_process());
    printw("   %d zombie\n", fetch_zombie_process());
}
