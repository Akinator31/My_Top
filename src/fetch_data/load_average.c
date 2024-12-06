/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** load_average
*/

#define _GNU_SOURCE
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include "my.h"

void get_number_average(char **result, char **str_token,
    char **separator)
{
    int counter = 0;

    while (counter < 3) {
        strcat(*result, *str_token);
        strcat(*result, " ");
        *str_token = strtok(NULL, *separator);
        counter += 1;
    }
}

char *fetch_load_average(void)
{
    FILE *loadavg_file = fopen("/proc/loadavg", "r");
    size_t len = 0;
    int counter = 0;
    char *time_file = NULL;
    char *separator = " ";
    char *str_token = NULL;
    char *result;

    if (loadavg_file == NULL) {
        fclose(loadavg_file);
        return NULL;
    }
    getline(&time_file, &len, loadavg_file);
    result = malloc(sizeof(char) * my_strlen(time_file));
    my_memset(result, '\0', sizeof(char) * my_strlen(time_file));
    str_token = strtok(time_file, separator);
    get_number_average(&result, &str_token, &separator);
    free(time_file);
    fclose(loadavg_file);
    return result;
}

void print_load_average(void)
{
    int i = 0;
    char *load_avg = fetch_load_average();

    if (load_avg == NULL) {
        printw(" load average: ");
        return;
    }
    printw(" load average: ");
    for (i = 0; i <= 3; i++)
        printw("%c", load_avg[i]);
    printw(", ");
    for (i++; i <= 8; i++)
        printw("%c", load_avg[i]);
    printw(", ");
    for (i++; i <= 13; i++)
        printw("%c", load_avg[i]);
    printw("\n");
    free(load_avg);
}
