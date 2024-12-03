/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** second_line
*/

#include <ncurses.h>
#include <dirent.h>
#include <stdlib.h>
#include "fetch_data.h"

int show_tasks_status(WINDOW *window)
{
    int *total_process = get_global_process_status();

    printw("Tasks:   %d total,   %d running,",
        total_process[TOTAL], total_process[RUNNING]);
    printw("   %d sleeping,   %d stopped,",
        total_process[SLEEPING], total_process[STOPPED]);
    printw("   %d zombie\n", total_process[ZOMBIE]);
    free(total_process);
}
