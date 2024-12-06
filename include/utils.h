/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** utils
*/

#ifndef INCLUDED_UTILS_H
    #define INCLUDED_UTILS_H
    #include <ncurses.h>
    #include <stdarg.h>
    #include "fetch_data.h"

int is_only_number(char *str);
//int fetch_process_status(char *filepath, char status);
char *open_and_read_file(char *filepath, int buffer_size);
void free_double_array(char **data);
int find_number(char *buffer, int index);
void set_timeout(int nb_window, ...);
int get_file_size(char *filepath);
int goto_next_line(char *buffer, int index);
char *get_filepath(char *part_one, char *part_two, char *part_three,
    int size_filepath);
processus_t *create_process(char *process_owner, int stat[], char *pid);
void my_free(int nb_value, ...);

#endif
