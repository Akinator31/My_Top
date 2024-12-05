/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** initialize_process_datastruct
*/

#include <stdlib.h>
#include "fetch_data.h"
#include "my.h"

processus_t *create_process(int pid, char *process_owner)
{
    processus_t *process_stat = malloc(sizeof(processus_t));

    process_stat->pid = pid;
    process_stat->user = my_strdup(process_owner);
    return process_stat;
}
