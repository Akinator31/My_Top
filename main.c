/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** main
*/

#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include "top_part.h"
#include "bottom_part.h"
#include "fetch_data.h"

int main(int ac, char **av)
{
    WINDOW *window = initscr();
    WINDOW *process_list = newwin(0, 0, 7, 0);

    wtimeout(window, 2000);
    wtimeout(process_list, 2000);
    noecho();
    while (true) {
        draw_top_part(window);
        print_title_bar(window);
        box(process_list, 0, 0);
        wrefresh(window);
        wrefresh(process_list);
        if (getch() == 113) {
            refresh();
            endwin();
            return 0;
        }
        wclear(window);
    }
    endwin();
    return 0;
}
