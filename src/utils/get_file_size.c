/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** get_file_size
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int get_file_size(char *filepath)
{
    struct stat info;

    stat(filepath, &info);
    if (stat(filepath, &info) == -1) {
        write(2, "Error retrieving file info\n", 28);
        return -1;
    }
    return info.st_size;
}
