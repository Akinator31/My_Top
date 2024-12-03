/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** draw_top_part
*/

#include <ncurses.h>
#include <stdlib.h>
#include "fetch_data.h"
#include "top_part.h"

void draw_top_part(WINDOW *window)
{
    show_uptime_load_average(window);
    show_tasks_status(window);
    show_cpu_stat(window);
    show_mem_stat(window);
}
