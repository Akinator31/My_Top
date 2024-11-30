/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** utils
*/

#ifndef INCLUDED_UTILS_H
    #define INCLUDED_UTILS_H

int is_only_number(char *str);
int fetch_process_status(char *filepath, char status);
char *open_and_read_file(char *filepath, int buffer_size);
void free_double_array(char **data);
int find_number(char *buffer, int index);

#endif
