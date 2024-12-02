/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** draw_top_part
*/

#include <ncurses.h>
#include <stdlib.h>
#include "fetch_data.h"
#include "top_part.h"

void draw_top_part(WINDOW *window)
{
    draw_first_line(window);
    draw_second_line(window);
    draw_third_line(window);
    draw_fourth_line(window);
    draw_fifth_line(window);
}
