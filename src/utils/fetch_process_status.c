/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** fetch_process_status
*/

#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>

int fetch_process_status(char *filepath, char status)
{
    int fd = open(filepath, O_RDONLY);
    int i = 0;
    char buffer[1000];

    read(fd, buffer, 1000);
    for (i = 0; buffer[i] != '\0'; i++) {
        if ((buffer[i] == 'S') && (buffer[i + 1] == 't')
            && (buffer[i + 2] == 'a'))
            break;
    }
    if (buffer[i + 7] == status) {
        close(fd);
        return 1;
    }
    close(fd);
    return 0;
}
