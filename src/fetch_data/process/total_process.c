/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** total_process
*/

#include <dirent.h>
#include "fetch_data.h"
#include "utils.h"

int fetch_total_process(void)
{
    DIR *current = opendir("/proc");
    struct dirent *dir_info = readdir(current);
    int nb_process = 0;

    while (dir_info) {
        if (is_only_number(dir_info->d_name))
            nb_process++;
        dir_info = readdir(current);
    }
    closedir(current);
    return nb_process;
}
