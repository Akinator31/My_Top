/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** top_part
*/

#ifndef INCLUDED_TOP_PART_H
    #define INCLUDED_TOP_PART_H
    #include <ncurses.h>

int show_cpu_stat(WINDOW *window);
int show_mem_stat(WINDOW *window);
int show_uptime_load_average(WINDOW *window);
int show_tasks_status(WINDOW *window);
void draw_top_part(WINDOW *window);

#endif
