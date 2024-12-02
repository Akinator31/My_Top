/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** process_listing
*/

#include <ncurses.h>
#include "utils.h"
#include "my.h"

void print_title_bar(WINDOW *window)
{
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    attron(COLOR_PAIR(1));
    printw("PID USER PR NI VIRT RES SHR S %%CPU %%MEM TIME+ COMMAND\n");
    attroff(COLOR_PAIR(1));
}
