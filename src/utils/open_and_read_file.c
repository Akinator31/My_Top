/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** open_file
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "utils.h"

char *open_and_read_file(char *filepath, int buffer_size)
{
    char *buffer = malloc(sizeof(char) * buffer_size);
    int fd = open(filepath, O_RDONLY);
    int read_result = 0;

    if (fd == -1) {
        free(buffer);
        return NULL;
    }
    read_result = read(fd, buffer, buffer_size);
    if (read_result == -1) {
        free(buffer);
        return NULL;
    }
    buffer[buffer_size - 1] = '\0';
    close(fd);
    return buffer;
}
