/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** process_status
*/

#include <dirent.h>
#include <fcntl.h>
#include <ncurses.h>
#include <unistd.h>
#include "fetch_data.h"
#include "utils.h"
#include "my.h"

int which_process(char buffer)
{
    if (buffer == 'R')
        return RUNNING;
    if ((buffer == 'S') || (buffer == 'I') || (buffer == 'D'))
        return SLEEPING;
    if (buffer == 'T')
        return STOPPED;
    if (buffer == 'Z')
        return ZOMBIE;
}

void get_process_status(int *result, char *filepath)
{
    int i = 0;
    char *buffer = open_and_read_file(filepath, 100);

    if (buffer == NULL)
        return;
    for (i = 0; buffer[i] != '\0'; i++) {
        if ((buffer[i] == 'S') && (buffer[i + 1] == 't')
            && (buffer[i + 2] == 'a'))
            break;
    }
    result[which_process(buffer[i + 7])] += 1;
    free(buffer);
}

int *get_global_process_status(void)
{
    DIR *current = opendir("/proc");
    struct dirent *dir_info = readdir(current);
    int *result = malloc(sizeof(int) * 5);
    char buffer[256];

    my_memset(result, 0, sizeof(int) * 5);
    buffer[255] = '\0';
    while (dir_info) {
        my_strcpy(buffer, "/proc/");
        if (is_only_number(dir_info->d_name)) {
            my_strcat(buffer, dir_info->d_name);
            my_strcat(buffer, "/status");
            get_process_status(result, buffer);
            result[TOTAL] += 1;
            my_memset(buffer, '\0', sizeof(char));
        }
        dir_info = readdir(current);
    }
    closedir(current);
    return result;
}
