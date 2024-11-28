/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** active_users
*/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <utmp.h>
#include <ncurses.h>
#include "linked_list.h"
#include "../../lib/my_lib/my.h"

int fetch_active_users(void)
{
    int fd = open("/var/run/utmp", O_RDONLY);
    struct utmp info;
    int nb_users = 0;

    while (read(fd, &info, sizeof(info)) != 0) {
        if (info.ut_type == USER_PROCESS && (my_strcmp(info.ut_line, "seat0") != 0)) {
            nb_users++;
        }
    }
    return nb_users;
}
