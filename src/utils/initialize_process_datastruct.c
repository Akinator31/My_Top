/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** initialize_process_datastruct
*/

#define _GNU_SOURCE
#include <stdlib.h>
#include "fetch_data.h"
#include "utils.h"
#include "my.h"



char get_status(char *pid)
{
    char *filepath = get_filepath("/proc/", pid, "/status", 256);
    FILE *status_file = fopen(filepath, "r");
    char *buffer = NULL;
    char result = 0;
    size_t len = 0;

    while (getline(&buffer, &len, status_file) != -1) {
        if ((buffer[0] == 'S') &&
            (buffer[1] == 't') &&
            (buffer[2] == 'a')) {
                fclose(status_file);
                result = buffer[7];
                free(buffer);
                free(filepath);
                return result;
            }
    }
    fclose(status_file);
    free(filepath);
    return 'P';
}

processus_t *create_process(char *process_owner, int stat[], char *pid)
{
    processus_t *process_stat = malloc(sizeof(processus_t));

    process_stat->pid = stat[0];
    process_stat->user = my_strdup(process_owner);
    process_stat->pr = stat[1];
    process_stat->ni = stat[2];
    process_stat->virt = stat[3];
    if (stat[4] == -1)
        process_stat->res = 0;
    else
        process_stat->res = stat[4];
    if (stat[5] == -1)
        process_stat->shr = 0;
    else
        process_stat->shr = stat[5];
    process_stat->status = get_status(pid);
    return process_stat;
}
