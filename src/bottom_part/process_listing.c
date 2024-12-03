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
    char *title = "PID USER PR NI VIRT RES SHR S %CPU %MEM TIME+ COMMAND";

    attron(A_STANDOUT);
    printw("%-*s", COLS, title);
    attroff(A_STANDOUT);
}
