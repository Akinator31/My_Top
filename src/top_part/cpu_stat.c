/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** third_line
*/

#include <ncurses.h>
#include <dirent.h>
#include "fetch_data.h"

int show_cpu_stat(WINDOW *window)
{
    printw("%%Cpu(s):  ");
    fetch_kernel_system_stat_user_mode();
}
