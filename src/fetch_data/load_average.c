/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** load_average
*/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ncurses.h>

char *fetch_load_average(void)
{
    int fd = open("/proc/loadavg", O_RDONLY);
    char *time_file = malloc(sizeof(char) * 1000);

    read(fd, time_file, 19);
    return time_file;
}

void print_load_average(void)
{
    int i = 0;
    char *load_avg = fetch_load_average();

    printw("load average: ");
    for (i = 0; i <= 3; i++)
        printw("%c", load_avg[i]);
    printw(", ");
    for (i++; i <= 8; i++)
        printw("%c", load_avg[i]);
    printw(", ");
    for (i++; i <= 13; i++)
        printw("%c", load_avg[i]);
    printw("\n");
    free(load_avg);
}
