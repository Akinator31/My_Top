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
#include "utils.h"

int main(int ac, char **av)
{
    WINDOW *window = initscr();
    WINDOW *process_list = newwin(0, 0, 7, 0);

    set_timeout(2, window, process_list);
    noecho();
    while (true) {
        draw_top_part(window);
        print_title_bar(window, process_list);
        wrefresh(window);
        wrefresh(process_list);
        if (wgetch(window) == 113) {
            refresh();
            endwin();
            return 0;
        }
        wclear(window);
        wclear(process_list);
    }
    endwin();
    return 0;
}
