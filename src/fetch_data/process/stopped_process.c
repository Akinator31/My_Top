/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** stopped_process
*/

#include <dirent.h>
#include <fcntl.h>
#include <ncurses.h>
#include <unistd.h>
#include "../../../include/fetch_data.h"
#include "../../../include/utils.h"
#include "../../../lib/my_lib/my.h"

int fetch_stopped_process(void)
{
    DIR *current = opendir("/proc");
    struct dirent *dir_info = readdir(current);
    char buffer[256];
    int nb_process = 0;
    int fd = 0;

    buffer[255] = '\0';
    while (dir_info) {
        my_strcpy(buffer, "/proc/");
        if (is_only_number(dir_info->d_name)) {
            my_strcat(buffer, dir_info->d_name);
            my_strcat(buffer, "/status");
            nb_process += fetch_process_status(buffer, 'T');
        }
        dir_info = readdir(current);
    }
    closedir(current);
    return nb_process;
}
