/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** uptime
*/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ncurses.h>
#include "my.h"

void analyse_uptime(char *time_file)
{
    int timestamp = my_getnbr(time_file);
    int days = timestamp / 60 / 60 / 24;
    int hours = timestamp / 60 / 60 - (days * 24);
    int minutes = (timestamp / 60) - (hours * 60);

    if ((days == 0) && (hours == 0)) {
        printw("%d min", minutes);
        return;
    }
    if ((days == 0) && ((hours > 0) && (hours < 24))) {
        if (minutes < 10)
            printw("%d:0%d", hours, minutes);
        else
            printw("%d:%d", hours, minutes);
        return;
    }
    if ((days > 0) && (hours == 0))
        printw("%d days, %d min", days, minutes);
    else
        printw("%d days, %d:%d", days, hours, minutes);
}

void fetch_uptime(void)
{
    int fd = open("/proc/uptime", O_RDONLY);
    char *time_file = malloc(sizeof(char) * 1000);

    if (fd == -1) {
        write(1, "Error opening rtc file\n", 24);
        return;
    }
    if (read(fd, time_file, 19) == -1) {
        write(1, "Error reading rtc file\n", 24);
        return;
    }
    analyse_uptime(time_file);
    free(time_file);
}
