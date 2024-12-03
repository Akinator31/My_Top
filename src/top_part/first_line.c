/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** first_line
*/

#include <ncurses.h>
#include <stdlib.h>
#include "fetch_data.h"

int draw_first_line(WINDOW *window)
{
    char *time = fetch_rtc_time();
    int nb_active_users = 0;

    printw("top - %s up ", time + 11);
    fetch_uptime();
    if (nb_active_users > 1)
        printw(", %d users, ", 0);
    else
        printw(", %d user, ", 0);
    print_load_average();
    free(time);
}
