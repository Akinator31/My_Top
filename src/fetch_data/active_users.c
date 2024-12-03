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
#include "my.h"
#include "my_list.h"

int fetch_active_users(void)
{
    int fd = open("/var/log/wtmp", O_RDONLY);
    linked_list_t *user_list = new_list();
    struct utmp info;
    int nb_users = 0;

    while (read(fd, &info, sizeof(info)) != 0) {
        if (!is_in_list(user_list, info.ut_user) &&
            (info.ut_type == USER_PROCESS)) {
            user_list = push_front_list(user_list, info.ut_user);
            nb_users += 1;
        }
    }
    clear_list(user_list);
    return nb_users;
}
