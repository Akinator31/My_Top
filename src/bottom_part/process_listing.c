/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** process_listing
*/

#include <ncurses.h>
#include "fetch_data.h"
#include "utils.h"
#include "my.h"

void print_process_info(WINDOW *process_list)
{
    int raw_counter = 0;
    linked_list_t *process_info = new_list();
    linked_list_t *temp;

    process_info = fetch_global_process_info();
    temp = process_info;
    while ((temp != NULL) && (raw_counter < (LINES - 7))) {
        wprintw(process_list, "%d %s\n", ((processus_t *)(temp->data))->pid,
            ((processus_t *)(temp->data))->user);
        temp = temp->next;
        raw_counter++;
    }
    clear_process_list(process_info);
}

void print_title_bar(WINDOW *window, WINDOW *process_list)
{
    char *title = "PID USER PR NI VIRT RES SHR S %CPU %MEM TIME+ COMMAND";

    attron(A_STANDOUT);
    printw("%-*s", COLS, title);
    attroff(A_STANDOUT);
    print_process_info(process_list);
}
