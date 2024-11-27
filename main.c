/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** main
*/

#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include "include/top_part.h"
#include "include/fetch_data.h"

int main(int ac, char **av)
{
    WINDOW *window = initscr();

    wtimeout(window, 3000);
    noecho();
    while (true) {
        draw_first_line(window);
        draw_second_line(window);
        wrefresh(window);
        if (wgetch(window) == 113)
            return 0;
        wclear(window);
    }
    endwin();
}
