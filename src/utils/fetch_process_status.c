/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** fetch_process_status
*/

#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include "utils.h"

int fetch_process_status(char *filepath, char status)
{
    char *buffer = open_and_read_file(filepath, 100);
    int i = 0;

    if (buffer == NULL)
        return 0;
    for (i = 0; buffer[i] != '\0'; i++) {
        if ((buffer[i] == 'S') && (buffer[i + 1] == 't')
            && (buffer[i + 2] == 'a'))
            break;
    }
    if (buffer[i + 7] == status) {
        free(buffer);
        return 1;
    }
    free(buffer);
    return 0;
}
