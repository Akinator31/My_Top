/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** set_timeout
*/

#include <stdarg.h>
#include "utils.h"

void set_timeout(int nb_window, ...)
{
    va_list window_list;
    WINDOW *temp;

    va_start(window_list, nb_window);
    for (int i = 0; i < nb_window; i++) {
        temp = (WINDOW *)va_arg(window_list, WINDOW *);
        wtimeout(temp, 2000);
    }
}
