/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** time
*/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char *fetch_rtc_time(void)
{
    int fd = open("/proc/driver/rtc", O_RDONLY);
    char *time_file = malloc(sizeof(char) * 1000);

    if (fd == -1) {
        write(1, "Error opening rtc file\n", 24);
        return NULL;
    }
    if (read(fd, time_file, 19) == -1) {
        write(1, "Error reading rtc file\n", 24);
        return NULL;
    }
    time_file[19] = '\0';
    return time_file;
}
